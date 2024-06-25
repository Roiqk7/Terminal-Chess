/*
Date: 22/06/2024

Description: This file implements formatter functions.

Notes: x
*/

#include <cmath>
#include <string>
#include <vector>
#include "../include/element.hpp"
#include "../include/exception.hpp"
#include "../include/formatter.hpp"
#include "../include/globals.hpp"
#include "../include/gui.hpp"
#include "../include/scene.hpp"
#include "../include/tool.hpp"

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
                        LOG_TRACE("Formatting scene {}", scene.name);

                        // Manage the scene's elements
                        manageSceneElements(scene);

                        // Format the scene's width and height
                        handleSceneWidth(scene);
                        handleSceneHeight(scene);

                        // Update scene's values
                        updateSceneValues(scene);
                }

                /*
                Manage the elements of the scene. Check if the elements are within the terminal dimensions.

                @param scene: The scene to be managed
                */
                // TODO Divide this function into several smaller functions
                void manageSceneElements(Scene& scene)
                {
                        // Get current scene dimensions
                        scene.calculateDimensions();

                        // Check the width of the elements
                        for (auto& element : scene.elements)
                        {
                                // Check if the element's width is greater than Globals::GUI_WIDTH
                                if (element.width > Globals::GUI_WIDTH)
                                {
                                        // TODO: This long block could be a function
                                        // Check if the element is required
                                        if (element.required)
                                        {
                                                // Log the error
                                                LOG_ERROR("Element {} is required in scene {} and it's width is greater than GUI_WIDTH", element.name, scene.name);

                                                // Log potential solution
                                                LOG_INFO("Calling getDimensions() to revalidate the GUI dimensions...");

                                                // Get the terminal dimensions
                                                GUI::getDimensions();

                                                // Check if the new dimensions are okay
                                                if (element.width > Globals::GUI_WIDTH)
                                                {
                                                        // Log the error
                                                        LOG_CRITICAL("Element {} is still required in scene {} and its width is still greater than GUI_WIDTH. Application will terminate.", element.name, scene.name);

                                                        // Throw an exception
                                                        throw Exception::TerminalSizeException("Element " + element.name + " is required in scene "
                                                                + scene.name + " but its width is greater than the terminal width. Application will terminate.",
                                                                true, true);
                                                }
                                        }
                                        // If not then we can remove the element
                                        else
                                        {
                                                // Log the warning
                                                LOG_WARN("Element {} is not required in scene {} and its width is greater than GUI_WIDTH.", element.name, scene.name);

                                                // Log info
                                                LOG_INFO("Element {} will be removed from scene {}.", element.name, scene.name);

                                                // Remove the element
                                                scene.removeElement(element.name);
                                        }
                                }
                                // Check if the element's height is greater than Globals::GUI_HEIGHT
                                if (element.height > Globals::GUI_HEIGHT || Globals::GUI_HEIGHT < scene.height + 1)
                                {
                                        // Check if the element is required
                                        if (element.required)
                                        {
                                                // Log the error
                                                LOG_ERROR("Element {} is required in scene {} and its height is greater than GUI_HEIGHT", element.name, scene.name);

                                                // Log potential solution
                                                LOG_INFO("Calling getDimensions() to revalidate the GUI dimensions...");

                                                // Get the terminal dimensions
                                                GUI::getDimensions();

                                                // Check if the new dimensions are okay
                                                if (element.height > Globals::GUI_HEIGHT || Globals::GUI_HEIGHT < scene.height + 1)
                                                {
                                                        // Log the error
                                                        LOG_CRITICAL("Element {} is still required in scene {} and its height is still greater than GUI_HEIGHT. Application will terminate.", element.name, scene.name);

                                                        // Throw an exception
                                                        throw Exception::TerminalSizeException("Element " + element.name + " is required in scene "
                                                                + scene.name + " and its height is greater than the terminal height. Application will terminate.",
                                                                false, true);
                                                }
                                        }
                                        // If not then we can remove the element
                                        else
                                        {
                                                // Log the warning
                                                LOG_WARN("Element {} is not required in scene {} but its height is greater than GUI_HEIGHT.", element.name, scene.name);

                                                // Log info
                                                LOG_INFO("Element {} will be removed from scene {}.", element.name, scene.name);

                                                // Remove the element
                                                scene.removeElement(element.name);

                                                // Recalculate the scene's dimensions
                                                scene.calculateDimensions();
                                        }
                                }
                        }
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
                                        std::string centeredLine = Tool::centerString(
                                                line, Globals::GUI_WIDTH, true);
                                        centeredGraphics.push_back(centeredLine);
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
                        size_t emptyLines = Globals::GUI_HEIGHT - scene.height
                                - 1;                                            // Note: We skip this one line as the last line is reserved for the cursor.

                        // No calculate the number of places where we can add empty lines
                        size_t emptyPlaces = scene.elements.size() - 1;

                        // Calculate the number of empty lines to add to each place
                        size_t emptyLinesPerPlace = emptyLines / (emptyPlaces + Globals::Constants::INFINITELY_SMALL);

                        // Calculate the number of remaining empty lines (those will be added to the first places equally)
                        size_t remainingEmptyLines = emptyLines % emptyPlaces;

                        // Calculate the number of remaining empty lines per place
                        size_t remainingEmptyLinesPerPlace = std::ceil(remainingEmptyLines
                                / (static_cast<double>(emptyPlaces) + Globals::Constants::INFINITELY_SMALL));

                        // Log the calculations
                        LOG_TRACE("Empty lines: {}", emptyLines);
                        LOG_TRACE("Empty places: {}", emptyPlaces);
                        LOG_TRACE("Empty lines per place: {}", emptyLinesPerPlace);
                        LOG_TRACE("Remaining empty lines: {}", remainingEmptyLines);
                        LOG_TRACE("Remaining empty lines per place: {}",
                                remainingEmptyLinesPerPlace);

                        // Add the empty lines in between the elements
                        std::vector<std::string> formattedGraphics;

                        // Add it all to the formatted graphics
                        for (auto element : scene.elements)
                        {
                                // Add the element's graphics
                                for (auto line : element.graphics)
                                {
                                        formattedGraphics.push_back(line);
                                }

                                // Check for end of empty places
                                if (emptyPlaces > 0)
                                {
                                        // Add empty lines
                                        for (size_t i = 0; i < emptyLinesPerPlace; i++)
                                        {
                                                formattedGraphics.push_back({" "});
                                        }

                                        // Add remaining empty lines
                                        if (remainingEmptyLines > 0)
                                        {
                                                for (size_t i = 0; i < remainingEmptyLinesPerPlace
                                                        && remainingEmptyLines > 0; i++)
                                                {
                                                        formattedGraphics.push_back({" "});
                                                        remainingEmptyLines--;
                                                }
                                        }

                                        // Decrement the empty places
                                        emptyPlaces--;
                                }
                        }

                        // Update the scene's graphics
                        scene.graphics = formattedGraphics;
                }

                /*
                Update the values of the scene.

                @param scene: The scene to be updated
                */
                void updateSceneValues(Scene& scene)
                {
                        // Make the scene processed
                        scene.raw = false;

                        // Calculate the new dimensions of the scene
                        scene.calculateDimensions();
                }
        }
}