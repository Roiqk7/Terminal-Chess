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
                EventHandler::Event handleUserInput();
                std::string getUserInput(const std::string& prompt, Globals::GameState gameState);
                bool validateUserInput(const std::string& input, Globals::GameState gameState);
                EventHandler::Event getEventFromUserInput(const std::string& input);
        }
}


#endif // !INPUT_HANDLER_HPP