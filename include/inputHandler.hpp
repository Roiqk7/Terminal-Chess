/*
Date: 20/06/2024

Description: This file defines functions which handle user input.

Notes: x
*/

#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <memory>
#include <string>
#include "event.hpp"
#include "eventHandler.hpp"
#include "globals.hpp"

namespace Chess
{
        namespace InputHandler
        {
                char getUserInput(const std::string& prompt);                   // Get user input from the console
                char getCharFromUserInput(const std::string& input);            // Get a char from user input
                void handleUniversalInput(char input,
                        std::unique_ptr<EventSystem::Event> event);             // Handle universal input
        }
}


#endif // !INPUT_HANDLER_HPP