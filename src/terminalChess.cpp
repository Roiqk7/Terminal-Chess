/*
Date: 21/06/2024

Description: This is the entry point of the program. It contains the main function.

Notes: x
*/

#include "../include/eventHandler.hpp"
#include "../include/globals.hpp"

using namespace Chess::EventSystem;

int main()
{
        // Set the log level
        SET_LOG_LEVEL_TRACE();

        // Create the application
        auto& application = EventHandler::getInstance();

        // Application loop
        while (application.run)
        {
                // Wait for an event
                application.waitEvent();

                // Process event queue
                application.processEventQueue();
        }

        return 0;
}