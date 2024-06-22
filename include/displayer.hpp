/*
Date: 22/06/2024

Description: This file defines displayer (renderer) related functions.

Notes: x
*/

#include <iostream>
#include <string>
#include <vector>
#include "scene.hpp"

namespace Chess
{
        namespace GUI
        {
                void display(Scene& scene);                               // Display the scene
                void display(const Scene& scene);                               // Display the scene
        }
}