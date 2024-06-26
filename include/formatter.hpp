/*
Date: 22/06/2024

Description: This file defines formatter functions.

Notes: x
*/

#ifndef FORMATTER_HPP
#define FORMATTER_HPP

#include <string>
#include <vector>
#include "scene.hpp"

namespace Chess
{
        namespace GUI
        {
                void formatScene(Scene& scene);                                         // Format the scene for display
                void manageSceneElements(Scene& scene);                                 // Manage the elements of the scene
                void handleSceneWidth(Scene& scene);                                    // Handle the width of the scene
                void handleSceneHeight(Scene& scene);                                   // Handle the height of the scene
                void updateSceneValues(Scene& scene);                                   // Update the values of the scene
        }
}

#endif // !FORMATTER_HPP