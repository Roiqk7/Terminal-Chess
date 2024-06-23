/*
Date: 23/06/2024

Description: This file contains functions and datatypes related to events.

Notes: x
*/

#ifndef EVENT_HPP
#define EVENT_HPP

#include <string>
#include "globals.hpp"

namespace Chess
{
        namespace Event
        {
                struct Event
                {
                public: // Variables
                // Input
                        char input;                                             // The input which triggered the event
                        Globals::GameState gameState;                           // The game in which the event was triggered
                // Output
                        Globals::Event event;                                   // The event attributed by the event handler
                        std::string eventName;                                  // The name of the event
                public: // Methods
                // Constructor
                        Event(char input, Globals::GameState gameState);
                };

                // TODO: Game event
        }
}

#endif // !EVENT_HPP