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
#include "../include/gui.hpp"
#include "../include/tool.hpp"

namespace Chess
{
        namespace GUI
        {
                /*
                Display a banner.
                */
                void displayBanner(const std::string& filePath)
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
                        }
                        else
                        {
                                // Failed to get terminal dimensions, use default values
                                setDimensions(64, 32);
                                throw std::runtime_error("Failed to get terminal dimensions");
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