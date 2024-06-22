/*
Date: 22/06/2024

Description: This file defines element related classes and functions.

Notes: x
*/

#include <string>
#include <vector>
#include "globals.hpp"

namespace Chess
{
        namespace GUI
        {
        // Element
                struct Element
                {
                public: // Variables
                        std::string name;                                       // Name of the element
                        std::string filePath;                                   // File path of the underlying asset
                        std::vector<std::string> graphics;                      // Graphics to be displayed
                        size_t width;                                           // Width of the element
                        size_t height;                                          // Height of the element
                public: // Constructors
                        Element(const std::string& filePath);                   // Constructor with file path
                        Element(const std::vector<std::string>& graphics);      // Constructor with graphics
                public: // Operators
                        bool operator==(const Element& element) const;          // Equality operator
                };
        }
}