/*
Date: 20/06/2024

Description: This file implements functions which handle user input.

Notes: x
*/

#include <iostream>
#include <string>
#include "../include/displayer.hpp"
#include "../include/inputHandler.hpp"
#include "../include/globals.hpp"
#include "../include/gui.hpp"
#include "../include/tool.hpp"

namespace Chess
{
        namespace InputHandler
        {
                /*
                Get user input from the console.

                @param prompt: The prompt to display to the user

                @return: The user's input
                */
                std::string getUserInput(const std::string& prompt)
                {
                        std::string input;

                        // Center the prompt
                        std::string centeredPrompt = prompt;

                        // Center the prompt
                        centeredPrompt = Tool::centerString(
                                centeredPrompt, Globals::GUI_WIDTH, false);

                        // Display the prompt
                        GUI::displayString(centeredPrompt, ' ');

                        // Get the input
                        std::cin >> input;

                        // Log the input
                        LOG_TRACE("User input: " + input);

                        return input;
                }
        }
}