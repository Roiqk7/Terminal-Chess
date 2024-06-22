/*
Date: 21/06/2024

Description: This file implements scene related classes and functions.

Notes: x
*/

#include <string>
#include <vector>
#include "../include/element.hpp"
#include "../include/globals.hpp"
#include "../include/scene.hpp"

namespace Chess
{
        namespace GUI
        {
                /*
                Default constructor for the scene.
                */
                Scene::Scene()
                        : width(0), height(0), raw(true) {}

                /*
                Add an element to the scene.

                @param element: The element to be added
                */
                void Scene::addElement(const Element& element)
                {
                        elements.push_back(element);
                }

                /*
                Remove an element from the scene.

                @param name: The name of the element to be removed
                */
                void Scene::removeElement(const std::string& name)
                {
                        for (size_t i = 0; i < elements.size(); i++)
                        {
                                if (elements[i].name == name)
                                {
                                        elements.erase(elements.begin() + i);
                                        return;
                                }
                        }
                }

                /*
                Update the graphics of an element.

                @param name: The name of the element to be updated
                @param graphics: The new graphics for the element
                */
                void Scene::updateElement(const std::string& name,
                        const std::vector<std::string>& graphics)
                {
                        for (size_t i = 0; i < elements.size(); i++)
                        {
                                if (elements[i].name == name)
                                {
                                        elements[i].graphics = graphics;
                                        return;
                                }
                        }
                }

        }
}