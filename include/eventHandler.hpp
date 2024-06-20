/*
Date: 20/06/2024

Description: This file contains functions and datatypes related to event handling.

Notes: x
*/

#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include <stack>
#include "globals.hpp"

namespace Chess
{
        namespace EventHandler
        {
                struct Event
                {
                        enum class Type                                         // Enum class to represent the type of an event
                        {
                                None = 0,GameStart, GameEnd, Move, Capture,
                                Check, Checkmate, Stalemate, Draw, Promotion,
                                Castling, EnPassant
                        };

                        Type type;                                              // Type of the event
                        Globals::Color player;                                  // Player who caused the event
                };

                using EventStack = std::stack<Event>;                           // Stack of events to keep track of the game history

                class Handler                                                   // Handles events
                {
                public: // Variables
                        EventStack eventStack;                                  // Stack of events to keep track of the game history
                private: // Variables
                        Event currentEvent;                                     // Current event ()
                        Event previousEvent;                                    // Previous event
                };
        }
}

#endif // !EVENT_HANDLER_HPP