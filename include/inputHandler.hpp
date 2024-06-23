/*
Date: 20/06/2024

Description: This file defines functions which handle user input.

Notes: x
*/

#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <string>
#include "eventHandler.hpp"
#include "globals.hpp"

namespace Chess
{
        namespace InputHandler
        {
                char getUserInput(const std::string& prompt);                   // Get user input from the console
                bool validateUserInput(const std::string& input,
                        Globals::GameState gameState);                          // Validate user input
                char getCharFromUserInput(const std::string& input);            // Get a char from user input
                //EventHandler::Event getEventFromUserInput(
                //        const std::string& input);                            // Translate user input into an event
        }
}


#endif // !INPUT_HANDLER_HPP