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
        // Application Start Event
                /*
                Starts the application.
                */
                ApplicationStartEvent::ApplicationStartEvent()
                {
                        // Log application start event was created
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
        // Application Main Menu Event
                /*
                Transition to the main menu.
                */
                ApplicationMainMenuEvent::ApplicationMainMenuEvent()
                {
                        // Log application main menu event was created
                        LOG_INFO("Application main menu event created.");
                }

                /*
                Executes the event.
                */
                void ApplicationMainMenuEvent::execute()
                {
                        // Transition to the main menu
                        application::mainMenu();
                }
        // Application Help Menu Event
                /*
                Transition to the help menu.
                */
                ApplicationHelpMenuEvent::ApplicationHelpMenuEvent()
                {
                        // Log application help menu event was created
                        LOG_INFO("Application help menu event created.");
                }

                /*
                Executes the event.
                */
                void ApplicationHelpMenuEvent::execute()
                {
                        // Transition to the help menu
                        application::helpMenu();
                }

        // Application End Event
                /*
                Ends the application.
                */
                ApplicationEndEvent::ApplicationEndEvent()
                {
                        // Log application end event was created
                        LOG_INFO("Application end event created.");
                }

                /*
                Executes the event.
                */
                void ApplicationEndEvent::execute()
                {
                        // End the application
                        application::endApplication();
                }
        // Application Exit Event
                /*
                Exits the application.
                */
                ApplicationExitEvent::ApplicationExitEvent()
                {
                        // Log application exit event was created
                        LOG_INFO("Application exit event created.");
                }

                /*
                Executes the event.
                */
                void ApplicationExitEvent::execute()
                {
                        // Exit the application
                        application::exitApplication();
                }

        }
}