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
                Display the main menu.
                */
                void displayMainMenu()
                {
                        // Display the main menu banner
                        displayGraphics("../assets/mainMenuBanner.txt");

                        // Display the main menu options
                        std::cout << "1. Start new game" << std::endl;
                        std::cout << "2. Load game" << std::endl;
                        std::cout << "3. Exit" << std::endl;
                }

                /*
                Display a banner.
                */
                void displayGraphics(const std::string& filePath)
                {
                        // Clear the screen
                        clearScreen();

                        // Get the banner from the file
                        std::string banner = Tool::readFileContents(filePath);

                        // Split the banner into lines
                        std::vector<std::string> lines = Tool::splitString(banner, '\n');

                        // Display the banner
                        for (const auto& line : lines)
                        {
                                size_t leadingSpaces = (Chess::Globals::GUI_WIDTH - line.length()) / 2;
                                std::cout << std::string(leadingSpaces, ' ') << line << std::endl;
                        }
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