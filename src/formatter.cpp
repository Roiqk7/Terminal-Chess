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
                        // Log the formatting
                        // TODO Switch to trace
                        LOG_INFO("Formatting scene {}", scene.name);

                        // Format the scene's width and height
                        handleSceneWidth(scene);
                        handleSceneHeight(scene);

                        // Update scene's values
                        scene.raw = false;
                        scene.calculateDimensions();
                }

                /*
                Handle the width of the scene. Center the graphics of each element.

                @param scene: The scene to be handled
                */
                void handleSceneWidth(Scene& scene)
                {
                        // Center the graphics of each element
                        for (auto& element : scene.elements)
                        {
                                std::vector<std::string> centeredGraphics;

                                // Each line must be GUI_WIDTH characters long
                                for (const auto& line : element.graphics)
                                {
                                        size_t padding = (Globals::GUI_WIDTH
                                                - line.length()) / 2;
                                        std::string centeredLine(padding, ' '); // Create left padding
                                        centeredLine += line;                   // Add the original line
                                        centeredLine += std::string(
                                                Globals::GUI_WIDTH
                                                - centeredLine.length(), ' ');  // Add right padding to fill up to GUI_WIDTH
                                        centeredGraphics.push_back(
                                                centeredLine);
                                }
                                element.graphics = centeredGraphics;            // Update the element's graphics with the centered version
                        }
                }

                /*
                Handle the height of the scene.

                @param scene: The scene to be handled
                */
                void handleSceneHeight(Scene& scene)
                {
                        // First we calculate the dimensions of the scene
                        scene.calculateDimensions();

                        // Calculate the number of empty lines to add to fit the GUI_HEIGHT
                        size_t emptyLines = Globals::GUI_HEIGHT - scene.height;

                        // No calculate the number of places where we can add empty lines
                        size_t emptyPlaces = scene.elements.size() - 1;

                        // Calculate the number of empty lines to add to each place
                        size_t emptyLinesPerPlace = emptyLines / emptyPlaces;

                        // Calculate the number of remaining empty lines (those will be added to the first places equally)
                        size_t remainingEmptyLines = emptyLines % emptyPlaces;

                        // Calculate the number of remaining empty lines per place
                        size_t remainingEmptyLinesPerPlace = remainingEmptyLines / emptyPlaces;

                        // Add the empty lines in between the elements
                        std::vector<std::string> formattedGraphics;

                        // First add the element
                        for (auto element : scene.elements)
                        {
                                for (auto line : element.graphics)
                                {
                                        formattedGraphics.push_back(line);
                                }

                                // Add empty lines
                                for (size_t i = 0; i < emptyLinesPerPlace; i++)
                                {
                                        formattedGraphics.push_back(" ");
                                }

                                // Add remaining empty lines
                                if (remainingEmptyLines > 0)
                                {
                                        for (size_t i = 0; i < remainingEmptyLinesPerPlace; i++)
                                        {
                                                formattedGraphics.push_back(" ");
                                                remainingEmptyLines--;
                                        }
                                }
                        }
                }
        }
}