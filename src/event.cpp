/*
Date: 23/06/2024

Description: This file contains implementations of functions and datatypes related to events.

Notes: x
*/

#include <memory>
#include <string>
#include "../include/application.hpp"
#include "../include/event.hpp"
#include "../include/globals.hpp"
#include "../include/gui.hpp"

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
                        LOG_INFO("Application start event created.");
                }

                /*
                Executes the event.
                */
                void ApplicationStartEvent::execute()
                {
                        // Start the application
                        application::startApplication();
                }
        }
}