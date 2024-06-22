/*
Date: 22/06/2024

Description: This file implements formatter functions.

Notes: x
*/

#include <string>
#include <vector>
#include "../include/element.hpp"
#include "../include/formatter.hpp"
#include "../include/globals.hpp"
#include "../include/scene.hpp"

namespace Chess
{
        namespace GUI
        {
                /*
                Format the scene for display.

                @param scene: The scene to be formatted
                */
                void formatScene(Scene& scene)
                {
                        handleSceneWidth(scene);
                        handleSceneHeight(scene);
                }

                /*
                Handle the width of the scene.

                @param scene: The scene to be handled
                */
                void handleSceneWidth(Scene& scene)
                {
                        // TODO: Implement handleSceneWidth
                }

                /*
                Handle the height of the scene.

                @param scene: The scene to be handled
                */
                void handleSceneHeight(Scene& scene)
                {
                        // TODO: Implement handleSceneHeight
                }
        }
}