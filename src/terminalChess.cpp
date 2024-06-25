/*
Date: 21/06/2024

Description: This is the entry point of the program. It contains the main function.

Notes: x
*/

#include "../include/eventHandler.hpp"
#include "../include/globals.hpp"

int main()
{
        // Set the log level
        SET_LOG_LEVEL_TRACE();

        // Application loop
        while (Chess::EventSystem::EventHandler::getInstance().run)
        {
                // Process events
                Chess::EventSystem::EventHandler::getInstance().processEvents();
        }

        return 0;
}