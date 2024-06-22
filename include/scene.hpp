/*
Date: 21/06/2024

Description: This file defines scene related classes and functions.

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
        // Scene
        // ? What about input elements? You will may need to remake the entire GUI system to make it work better???
        // ! Do not worry... it will likely take few hours and save some in the end...
                class Scene
                {
                public: // Variables
                        std::vector<Element> elements;                          // Elements of the scene (sorted in order of display)
                public: // Methods
                // Constructors
                        Scene();                                                // Default constructor
                // GUI
                        void display();                                         // Display the scene
                // Scene management
                        void addElement(const Element& element);                // Add an element to the scene
                        void removeElement(const size_t& index);                // Remove an element from the scene
                        void updateElement(
                                const std::vector<std::string>& graphics);      // Update the graphics of an element
                };
        }
}