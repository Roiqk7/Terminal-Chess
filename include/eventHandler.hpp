/*
Date: 20/06/2024

Description: This file defines functions related to event handling.

Notes: x
*/

#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include <stack>
#include "event.hpp"
#include "globals.hpp"

namespace Chess
{
        namespace EventHandler
        {
                Event::Event handleEvent(const char& input, const Globals::GameState gameState);
                bool isInputValid(const char& input, Globals::GameState gameState);
                Event::Event determineEvent(const char input, Globals::GameState gameState);
        }
}

#endif // !EVENT_HANDLER_HPP