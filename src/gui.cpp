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

                        // Add header space
                        GUI::addHeaderSpace();

                        // Display welcome banner
                        GUI::displayGraphics("../assets/welcomeBanner.txt");

                        // Wait for a few seconds
                        Tool::wait(2);

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

                        // Add header space
                        addHeaderSpace();

                        // Display the main menu banner
                        displayGraphics("../assets/mainMenuBanner.txt");

                        // Add few new lines
                        addNewLine(2);

                        // Display the main menu options
                        displayGraphics("../assets/mainMenu.txt");
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