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
                struct Element
                {
                public: // Variables
                        std::string name;                                       // Name of the element
                        std::string filePath;                                   // File path of the underlying asset
                        std::vector<std::string> graphics;                      // Graphics to be displayed
                        size_t width;                                           // Width of the element
                        size_t height;                                          // Height of the element
                        bool required;                                          // Whether the element is required and must be displayed or not
                        bool userInput;                                         // Whether the element requires user input or not
                public: // Constructors
                        Element(const std::string& name,
                                const std::string& filePath,
                                const bool required, const bool userInput);     // Constructor with file path
                        Element(const std::string& name,
                                const std::vector<std::string>& graphics,
                                const bool required, const bool userInput);     // Constructor with graphics
                public: // Operators
                        bool operator==(const Element& element) const;          // Equality operator
                private: // Methods
                        void calculateDimensions();                             // Calculate the dimensions of the element
                };
        }
}