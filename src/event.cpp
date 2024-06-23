/*
Date: 23/06/2024

Description: This file contains implementations of functions and datatypes related to events.

Notes: x
*/

#include <string>
#include "../include/event.hpp"
#include "../include/globals.hpp"

namespace Chess
{
        namespace Event
        {
                // Constructor
                Event::Event(std::string input, Globals::GameState gameState)
                        : input(input), gameState(gameState),
                        event(Globals::Event::None) {}
        }
}