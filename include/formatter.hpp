/*
Date: 22/06/2024

Description: This file defines formatter functions.

Notes: x
*/

#include <string>
#include <vector>
#include "element.hpp"
#include "globals.hpp"
#include "scene.hpp"

namespace Chess
{
        namespace GUI
        {
                void formatScene(Scene& scene);                                         // Format the scene for display
                void handleSceneHeight(Scene& scene);                                   // Handle the height of the scene
                void handleSceneWidth(Scene& scene);                                    // Handle the width of the scene
                // Note: Maybe scenes should just be elements and the graphics will be given here
                // That way there is no problem with 'preformatted' graphics where the width will then be wrong
                // ? Check if the above is relevant and just make sure graphics is given here.
        }
}