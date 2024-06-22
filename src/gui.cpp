/*
Date: 21/06/2024

Description: This file implements functions which provide the GUI for the application.

Notes: x
*/

#include <fstream>
#include <iostream>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>
#include "../include/displayer.hpp"
#include "../include/element.hpp"
#include "../include/exception.hpp"
#include "../include/formatter.hpp"
#include "../include/globals.hpp"
#include "../include/gui.hpp"
#include "../include/scene.hpp"
#include "../include/tool.hpp"

namespace Chess
{
        namespace GUI
        {
                /*
                Display the intro. Actually, it also prepares the terminal for the
                application by getting the terminal dimensions and clearing the
                screen.
                */
                void displayIntro()
                {
                        // Get the terminal dimensions
                        getDimensions();

                        // Clear the screen
                        clearScreen();

                        // Create the intro scene
                        Scene introScene;

                        // Add the elements to the intro scene
                        introScene.addElement(Element("Welcome", Globals::Constants::WELCOME_BANNER_PATH, true, false));

                        // Format the intro scene
                        formatScene(introScene);

                        // Display the intro scene
                        display(introScene);

                        /*
                        Header

                        Welcome

                        Footer
                        */
                }

                /*
                Display the main menu.
                */
                void displayMainMenu()
                {
                        /*
                        Header

                        Main Menu Banner

                        Main Menu

                        Input Separator
                        */
                }

                /*
                Display the ending.
                */
                void displayEnding()
                {
                        /*
                        Header

                        Farewell

                        Footer
                        */
                }

                /*
                Display the header.
                */
                void displayHeader()
                {
                        // Get the header
                        std::vector<std::string> header = mergeHeaders();

                        // Display the header
                        //! displayGraphics(header);
                }

                /*
                Merge the left and right headers.
                */
                std::vector<std::string> mergeHeaders()
                {
                        // Left header
                        std::vector<std::string> leftHeader = Tool::splitString(
                                Tool::readFileContents(Globals::Constants::HEADER_LEFT_PATH), '\n');

                        // Right header
                        std::vector<std::string> rightHeader = Tool::splitString(
                                Tool::readFileContents(Globals::Constants::HEADER_RIGHT_PATH), '\n');

                        // Merge the headers
                        return merge(leftHeader, rightHeader, Chess::Globals::GUI_WIDTH, " ");
                }

                /*
                Display the footer.
                */
                void displayFooter()
                {
                        // Get the footer
                        std::vector<std::string> footer = mergeFooters();

                        // Display the footer
                        //! displayGraphics(footer);
                }

                /*
                Merge the left and right footers.
                */
                std::vector<std::string> mergeFooters()
                {
                        // Left footer
                        std::vector<std::string> leftFooter = Tool::splitString(
                                Tool::readFileContents(Globals::Constants::FOOTER_LEFT_PATH), '\n');

                        // Right footer
                        std::vector<std::string> rightFooter = Tool::splitString(
                                Tool::readFileContents(Globals::Constants::FOOTER_RIGHT_PATH), '\n');

                        // Merge the footers
                        return merge(leftFooter, rightFooter, Chess::Globals::GUI_WIDTH, " ");
                }

                /*
                Merge two vectors of strings into one vector of strings with the
                specified width and filler to fill the gap between the left and right.

                @param left: The left vector of strings.
                @param right: The right vector of strings.
                */
                std::vector<std::string> merge(const std::vector<std::string>& left, const std::vector<std::string>& right,
                        const size_t& width, const std::string& filler)
                {
                        // Merged vector
                        std::vector<std::string> merged;

                        // Get size (width) of the left and right vectors
                        size_t leftSize = left[0].size();
                        size_t rightSize = right[0].size();

                        // Calculate the number of fillers needed
                        size_t fillersNeeded = (width - leftSize - rightSize) / filler.size();

                        // If the width is not enough to fit the left and right, throw an exception
                        if (fillersNeeded < 0)
                        {
                                // Invalid width
                                throw Exception::RunTimeException(
                                        "Negative size provided. Invalid width.");
                        }
                        // If the width is not enough to fit the left and right, throw an exception
                        else if (fillersNeeded < leftSize + rightSize)
                        {
                                // If the width is not enough to fit the left and right, throw an exception
                                throw Exception::InvalidInputException(
                                        "The width is not enough to fit the left and right part of the graphics.");
                        }
                        // If the width is not divisible by the fillers width, throw an exception
                        // Note: Maybe remove and handle more properly without an exception
                        else if (width % filler.size() != 0)
                        {
                                // If the width is not divisible by the fillers width, throw an exception
                                throw Exception::InvalidInputException(
                                        "The width is not divisible by the fillers needed.");
                        }

                        // Create the filler string
                        std::string fillers = std::string(fillersNeeded, filler[0]);

                        // Merge the left and right
                        for (size_t i = 0; i < left.size(); i++)
                        {
                                merged.push_back(left[i] + fillers + right[i]);
                        }

                        return merged;
                }

                /*
                Repeat a pattern a certain number of times.

                @param filePath: The path to the file containing the pattern.
                @param count: The number of times to repeat the pattern.
                @param delimiter: The delimiter to split the pattern.
                */
                std::vector<std::string> repeatPattern(const std::string& filePath, const size_t& count, const char& delimiter)
                {
                        // Get the pattern
                        std::vector<std::string> pattern = Tool::splitString(
                                Tool::readFileContents(filePath), delimiter);

                        // Repeated pattern
                        std::vector<std::string> repeatedPattern;

                        // Repeat the pattern
                        for (size_t i = 0; i < pattern.size(); i++)
                        {
                                // New line with repeated pattern
                                std::string newLine;

                                // Add the pattern to the new line specified number of times
                                for (int j = count; j > 0; j--)
                                {
                                        newLine += pattern[i];
                                }

                                // Add the new line to the repeated pattern
                                repeatedPattern.push_back(newLine);
                        }

                        return repeatedPattern;
                }

                /*
                Get the dimensions of the terminal and set them in the globals.
                */
                void getDimensions()
                {
                        // Get the terminal dimensions
                        struct winsize w;
                        // Use STDOUT_FILENO for standard output or 0 for standard input
                        if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0)
                        {
                                setDimensions(w.ws_col, w.ws_row);

                                // Log terminal dimensions
                                LOG_INFO("Terminal dimensions: {}x{}", w.ws_col, w.ws_row);
                        }
                        else
                        {
                                // Default terminal dimensions
                                size_t width = 64;
                                size_t height = 32;

                                // Failed to get terminal dimensions, use default values
                                setDimensions(width, height);

                                // Log warning
                                LOG_WARN("Failed to get terminal dimensions, using default values: {}x{}", width, height);
                        }
                }

                /*
                Set the dimensions of the terminal.

                @param width: The width of the terminal.
                @param height: The height of the terminal.
                */
                void setDimensions(const size_t& width, const size_t& height)
                {
                        // Set the terminal dimensions
                        Chess::Globals::GUI_WIDTH = width;
                        Chess::Globals::GUI_HEIGHT = height;
                }

                /*
                Clear the screen.
                */
                void clearScreen()
                {
                        // Clear the screen
                        std::cout << "\033[2J\033[1;1H";
                }
        }
}