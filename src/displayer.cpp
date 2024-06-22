/*
Date: 22/06/2024

Description: This file implements displayer (renderer) related functions.

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
                void display(Scene& scene)
                {
                        // Display the graphics line by line
                        for (const auto& line : scene.graphics)
                        {
                                std::cout << line << '\n';
                        }
                }

                /*
                Display the scene.

                @param scene: The scene to be displayed
                */
                void display(const Scene& scene)
                {
                        // Display the graphics line by line
                        for (const auto& line : scene.graphics)
                        {
                                std::cout << line << '\n';
                        }
                }
        }
}