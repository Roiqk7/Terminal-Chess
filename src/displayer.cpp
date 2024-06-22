/*
Date: 22/06/2024

Description: This file implements displayer (renderer) related functions.

Notes: x
*/

#include <iostream>
#include <string>
#include <vector>
#include "../include/displayer.hpp"
#include "../include/globals.hpp"
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
                        // Log the display
                        LOG_TRACE("Displaying {} scene {} with width {} and height {}",
                                scene.raw ? "raw" : "formatted", scene.name, scene.width, scene.height);

                        // Display the graphics line by line
                        for (const auto& line : scene.graphics)
                        {
                                std::cout << line << '\n';
                        }
                }
        }
}