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

                        // Display the banner
                        std::cout << banner << std::endl;
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