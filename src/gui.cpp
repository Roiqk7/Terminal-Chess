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
#include "../include/exception.hpp"
#include "../include/globals.hpp"
#include "../include/gui.hpp"
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
                        GUI::getDimensions();

                        // Clear the screen
                        GUI::clearScreen();

                        // Add header
                        GUI::displayHeader();

                        // Display welcome banner
                        GUI::displayGraphics("../assets/welcomeBanner.txt");

                        // DEBUG: Delete
                        GUI::addNewLine(10);

                        // Display the footer
                        GUI::displayFooter();

                        // DEBUG: Delete
                        GUI::addNewLine(2);

                        // User input divisor
                        GUI::displayGraphics("../assets/userInputDivisor.txt");

                        // Wait for a few seconds
                        Tool::wait(30);

                        // Clear the screen
                        GUI::clearScreen();
                }

                /*
                Display the main menu.
                */
                void displayMainMenu()
                {
                        // Clear the screen
                        clearScreen();

                        // Add header
                        GUI::displayHeader();

                        // Display the main menu banner
                        displayGraphics("../assets/mainMenuBanner.txt");

                        // Add few new lines
                        addNewLine(2);

                        // Display the main menu options
                        displayGraphics("../assets/mainMenu.txt");

                        // DEBUG: Delete
                        GUI::addNewLine(10);

                        // Display the footer
                        GUI::displayFooter();

                        // DEBUG: Delete
                        GUI::addNewLine(2);

                        // Wait for a few seconds
                        Tool::wait(30);
                }

                /*
                Display the ending.
                */
                void displayEnding()
                {
                        // Clear the screen
                        clearScreen();

                        // Add header
                        GUI::displayHeader();

                        // Display the ending banner
                        displayGraphics("../assets/farewellBanner.txt");

                        // Some new lines
                        GUI::addNewLine(10);

                        // Display the footer
                        GUI::displayFooter();

                        // Bit more new lines
                        GUI::addNewLine(2);

                        // Wait for a few seconds
                        Tool::wait(30);
                }

                /*
                Display the graphics by reading the file and displaying it on the
                console. It centers the graphics and displays it line by line.

                @param filePath: The path to the file containing the graphics.
                */
                void displayGraphics(const std::string& filePath)
                {
                        // Get the graphics from the file
                        std::string graphics = Tool::readFileContents(filePath);

                        // Split the graphics into lines
                        std::vector<std::string> graphicsInLines = Tool::splitString(graphics, '\n');

                        // Display the graphics
                        displayGraphics(graphicsInLines);
                }

                /*
                Display the graphics from a vector of strings.

                @param graphics: The graphics to display.
                */
                void displayGraphics(const std::vector<std::string>& graphics)
                {
                        // Display the graphics line by line
                        for (const auto& line : graphics)
                        {
                                size_t leadingSpaces = (Chess::Globals::GUI_WIDTH
                                        - line.length()) / 2;
                                std::cout << std::string(leadingSpaces, ' ')
                                        << line << std::endl;
                        }
                }

                /*
                Display the header.
                */
                void displayHeader()
                {
                        // Get the header
                        std::vector<std::string> header = mergeHeaders();

                        // Display the header
                        displayGraphics(header);
                }

                /*
                Merge the left and right headers.
                */
                std::vector<std::string> mergeHeaders()
                {
                        // Left header
                        std::vector<std::string> leftHeader = Tool::splitString(Tool::readFileContents("../assets/headerLeft.txt"), '\n');

                        // Right header
                        std::vector<std::string> rightHeader = Tool::splitString(Tool::readFileContents("../assets/headerRight.txt"), '\n');

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
                        displayGraphics(footer);
                }

                /*
                Merge the left and right footers.
                */
                std::vector<std::string> mergeFooters()
                {
                        // Left footer
                        std::vector<std::string> leftFooter = Tool::splitString(Tool::readFileContents("../assets/footerLeft.txt"), '\n');

                        // Right footer
                        std::vector<std::string> rightFooter = Tool::splitString(Tool::readFileContents("../assets/footerRight.txt"), '\n');

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
                                throw Exception::RunTimeException("Negative size provided. Invalid width.");
                        }
                        else if (fillersNeeded < leftSize + rightSize)
                        {
                                // If the width is not enough to fit the left and right, throw an exception
                                throw Exception::InvalidInputException("The width is not enough to fit the left and right part of the graphics.");
                        }
                        else if (width % filler.size() != 0)
                        {
                                // If the width is not divisible by the fillers width, throw an exception
                                throw Exception::InvalidInputException("The width is not divisible by the fillers needed.");
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
                                size_t width = 0;
                                size_t height = 0;

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
                Add a new line(s) to the console.

                @param count: The number of new lines to add.
                */
                void addNewLine(const int& count)
                {
                        // Add new line(s)
                        for (int i = 0; i < count; i++)
                        {
                                std::cout << std::endl;
                        }
                }

                /*
                Add a header space based on the terminal height.
                */
                void addHeaderSpace()
                {
                        // Add header space
                        addNewLine(Chess::Globals::GUI_HEIGHT / 6);             // 1/6th of the terminal height (1/6th because it looks the best)
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