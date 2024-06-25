/*
Date: 21/06/2024

Description: This is the entry point of the program. It contains the main function.

Notes: x
*/

#include "../include/eventHandler.hpp"
#include "../include/globals.hpp"

using Chess::EventSystem::EventHandler;

int main()
{
        // Set the log level
        SET_LOG_LEVEL_TRACE();

        // Application loop
        while (EventHandler::getInstance().run)
        {
                // Wait for an event
                EventHandler::getInstance().waitEvent();

                // Process events
                EventHandler::getInstance().processEventQueue();
        }

        return 0;
}