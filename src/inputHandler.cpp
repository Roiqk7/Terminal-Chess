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
                Handle user input.

                @param input: The user's input
                @param event: The event which asked for the input
                */
                void handleInput(char input,
                        std::unique_ptr<EventSystem::Event> event)
                {
                        // Process user input
                        switch (input)
                        {
                                case 'm':
                                        // Display the main menu
                                        return EventSystem::EventHandler::getInstance().submit(
                                                std::make_unique<
                                                        EventSystem::ApplicationMainMenuEvent>());
                                case 'h':
                                        // Display the help menu
                                        return EventSystem::EventHandler::getInstance().submit(
                                                std::make_unique<
                                                        EventSystem::ApplicationHelpMenuEvent>());
                                case 'r':
                                        // Reset the GUI
                                        EventSystem::EventHandler::getInstance().submit(
                                                std::make_unique<
                                                        EventSystem::ResetGUIEvent>());
                                        break; // Deliberately return to the event which asked for the input to reset the GUI
                                case 'q':
                                        // Undo the last event
                                        return EventSystem::EventHandler::getInstance().undo();
                                case 'u': // Debug
                                        // Undo the last event
                                        return EventSystem::EventHandler::getInstance().undo();
                                case 'x':
                                        // Quit the application
                                        return EventSystem::EventHandler::getInstance().submit(
                                                std::make_unique<
                                                        EventSystem::ApplicationExitEvent>());
                                default:
                                        // Not an universal input
                                        break;
                        }

                        // Return to the event which asked for the input
                        return EventSystem::EventHandler::getInstance().submit(
                                std::move(event));
                }
        }
}