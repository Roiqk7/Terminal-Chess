/*
Date: 20/06/2024

Description: This file defines functions which handle user input.

Notes: x
*/

#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <string>
#include "../include/eventHandler.hpp"
#include "../include/globals.hpp"

namespace Chess
{
        namespace InputHandler
        {
                EventHandler::Event handleUserInput();                          // Handles user input from start to finish
                std::string getUserInput(const std::string& prompt,
                        Globals::GameState gameState);                          // Get user input from the console
                bool validateUserInput(const std::string& input,
                        Globals::GameState gameState);                          // Validate user input
                EventHandler::Event getEventFromUserInput(
                        const std::string& input);                              // Translate user input into an event
        }
}


#endif // !INPUT_HANDLER_HPP