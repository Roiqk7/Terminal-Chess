/*
Date: 21/06/2024

Description: This file defines scene related classes and functions.

Notes: x
*/

#ifndef SCENE_HPP
#define SCENE_HPP

#include <string>
#include <vector>
#include "element.hpp"
#include "globals.hpp"

namespace Chess
{
        namespace GUI
        {
                class Scene
                {
                public: // Variables
                        std::vector<std::string> graphics;                      // Graphics to be displayed
                        std::vector<Element> elements;                          // Elements in the scene
                        size_t width;                                           // Width of the scene
                        size_t height;                                          // Height of the scene
                        bool raw;                                               // Whether the scene is raw (not ready for display) or not
                public: // Methods
                // Constructors
                        Scene();                                                // Default constructor
                // Dimensions
                        void calculateDimensions();                             // Calculate the dimensions of the scene
                // Scene management
                        void addElement(const Element& element);                // Add an element to the scene
                        void removeElement(const std::string& name);            // Remove an element from the scene
                        void updateElement(const std::string& name,
                                const std::vector<std::string>& graphics);      // Update the graphics of an element
                };
        }
}

#endif // !SCENE_HPP