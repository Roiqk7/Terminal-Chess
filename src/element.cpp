/*
Date: 22/06/2024

Description: This file implements element related classes and functions.

Notes: x
*/

#include <string>
#include <vector>
#include "../include/element.hpp"
#include "../include/globals.hpp"
#include "../include/tool.hpp"

namespace Chess
{
        namespace GUI
        {
                /*
                Constructor with file path for the element.

                @param name: The name of the element
                @param filePath: The file path of the underlying asset
                @param required: Whether the element is required and must be displayed or not
                @param userInput: Whether the element requires user input or not
                */
                Element::Element(const std::string& name,
                        const std::string& filePath,
                        const bool required, const bool userInput)
                        : name(name), filePath(filePath), width(0), height(0),
                        required(required), userInput(userInput), raw(true)
                {
                        // Load the graphics
                        graphics = Tool::splitString(Tool::readFileContents(filePath), '\n');

                        // Calculate the dimensions
                        calculateDimensions();
                }

                /*
                Constructor with graphics for the element.

                @param name: The name of the element
                @param graphics: The graphics to be displayed
                @param required: Whether the element is required and must be displayed or not
                @param userInput: Whether the element requires user input or not
                */
                Element::Element(const std::string& name,
                        const std::vector<std::string>& graphics,
                        const bool required, const bool userInput)
                        : name(name), graphics(graphics), width(0), height(0),
                        required(required), userInput(userInput), raw(true)
                {
                        // Calculate the dimensions
                        calculateDimensions();
                }

                /*
                Equality operator for the element.

                @param element: The element to compare with
                @return: Whether the elements are equal or not
                */
                bool Element::operator==(const Element& element) const
                {
                        return name == element.name;
                }

                /*
                Calculate the dimensions of the element.
                */
                void Element::calculateDimensions()
                {
                        // Calculate the width (maximum line length)
                        for (auto& line : graphics)
                        {
                                if (line.size() > width)
                                {
                                        width = line.size();
                                }
                        }

                        // Calculate the height (number of lines)
                        height = graphics.size();
                }

        }
}