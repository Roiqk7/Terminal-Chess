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
#include "../include/eventHandler.hpp"
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
                char getUserInput(const std::string& prompt)
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

                        // Get the first char of the input
                        char inputChar = getCharFromUserInput(input);

                        // Lowercase the input
                        inputChar = std::tolower(
                                static_cast<unsigned char>(inputChar));

                        // Log the input
                        LOG_TRACE("User input: {}", input);

                        // Log the input char
                        LOG_TRACE("User input char: {}", inputChar);

                        return inputChar;
                }

                /*
                Get a char from user input.

                @param input: The user's input

                @return: The first char of the input
                */
                char getCharFromUserInput(const std::string& input)
                {
                        // Check if the input is empty
                        if (input.empty())
                        {
                                // Log the error
                                LOG_ERROR("Input is empty.");

                                return '\0';
                        }

                        return input[0];
                }

                /*
                Handle universal input.

                @param input: The user's input
                */
                void handleUniversalInput(char input)
                {
                        // Process user input
                        switch (input)
                        {
                                case 'h':
                                        // Display the help menu
                                        EventSystem::EventHandler::getInstance().submit(
                                                std::make_unique<
                                                        EventSystem::ApplicationHelpMenuEvent>());
                                        break;
                                case 'q':
                                        // Undo the last event
                                        EventSystem::EventHandler::getInstance().undo();
                                        break;

                                case 'x':
                                        // Quit the application
                                        EventSystem::EventHandler::getInstance().submit(
                                                std::make_unique<
                                                        EventSystem::ApplicationExitEvent>());
                                        break;
                                default:
                                        // Not an universal input
                                        break;
                        }
                }
        }
}