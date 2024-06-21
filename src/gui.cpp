/*
Date: 21/06/2024

Description: This file implements functions which provide the GUI for the application.

Notes: x
*/

#include <fstream>
#include <iostream>
#include <string>
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
                Clear the screen.
                */
                void clearScreen()
                {
                        // Clear the screen
                        std::cout << "\033[2J\033[1;1H";
                }
        }
}