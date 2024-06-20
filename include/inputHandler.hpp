/*
Date: 20/06/2024

Description: This file defines functions which handle user input.

Notes: x
*/

#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <string>
#include "../include/eventHandler.hpp"

namespace Chess
{
        namespace InputHandler
        {
                EventHandler::Event handleUserInput(); // NOTE:
                std::string getUserInput(const std::string& prompt);

        }
}


#endif // !INPUT_HANDLER_HPP