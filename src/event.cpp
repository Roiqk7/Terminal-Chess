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
                /*
                Constructs an event.

                @param input The input which triggered the event
                @param gameState The game in which the event was triggered
                */
                Event::Event(char input, Globals::GameState gameState)
                        : input(input), gameState(gameState),
                        event(Globals::Event::None) {}

        // Setter
                /*
                Sets the event and its name.

                @param event The event to set
                @param eventName The name of the event
                */
                void Event::setEvent(Globals::Event event, std::string eventName)
                {
                        this->event = event;
                        this->eventName = eventName;
                }
        }
}