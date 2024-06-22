/*
Date: 22/06/2024

Description: This file implements displayer (renderer) related classes and functions.

Notes: x
*/

#include <iostream>
#include <string>
#include <vector>
#include "../include/scene.hpp"

namespace Chess
{
        namespace GUI
        {
                /*
                Display the scene.

                @param scene: The scene to be displayed
                */
                void display(const Scene& scene)
                {
                        // Display the graphics line by line
                        for (const auto& line : scene.graphics)
                        {
                                size_t leadingSpaces = (Chess::Globals::GUI_WIDTH
                                        - line.length()) / 2;
                                std::cout << std::string(leadingSpaces, ' ')
                                        << line << std::endl;
                        }
                }
        }
}