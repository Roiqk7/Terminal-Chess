/*
Date: 20/06/2024

Description: This file implements functions which handle user input.

Notes: x
*/

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include "../include/displayer.hpp"
#include "../include/inputHandler.hpp"
#include "../include/globals.hpp"
#include "../include/gui.hpp"
#include "../include/tool.hpp"
#include "../include/validator.hpp"

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
                        std::getline(std::cin, input);

                        // Trim the input
                        input = Tool::trimString(input);

                        // Lowercase the input
                        std::transform(input.begin(), input.end(), input.begin(),
                                [](unsigned char c){ return std::tolower(c); });

                        // Add a newline
                        std::cout << std::endl;

                        // Log the input
                        LOG_TRACE("User input: " + input);

                        return input;
                }

                /*
                Validate user input.

                @param input: The user's input
                @param gameState: The current game state

                @return: True if the input is valid, false otherwise
                */
                bool validateUserInput(const std::string& input,
                        Globals::GameState gameState)
                {
                        // Check empty input
                        if (input.empty())
                        {
                                return false;
                        }

                        // Check if the input is valid
                        return Validator::validateGameState(input, gameState);
                }
        }
}