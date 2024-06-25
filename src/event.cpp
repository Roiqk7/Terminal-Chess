/*
Date: 23/06/2024

Description: This file contains implementations of functions and datatypes related to events.

Notes: x
*/

#include <memory>
#include <string>
#include "../include/event.hpp"
#include "../include/globals.hpp"

namespace Chess
{
        namespace EventSystem
        {
                /*
                Starts the application.
                */
                ApplicationStartEvent::ApplicationStartEvent()
                {
                        // Log application start
                        LOG_INFO("Application started.");
                }

                /*
                Executes the event.
                */
                void ApplicationStartEvent::execute()
                {

                }
        }
}