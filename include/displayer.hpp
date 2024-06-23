/*
Date: 22/06/2024

Description: This file defines displayer (renderer) related functions.

Notes: x
*/

#ifndef DISPLAYER_HPP
#define DISPLAYER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "scene.hpp"

namespace Chess
{
        namespace GUI
        {
                void display(const Scene& scene);                               // Display the scene
                void displayString(const std::string& str);                     // Display a string
        }
}

#endif // !DISPLAYER_HPP