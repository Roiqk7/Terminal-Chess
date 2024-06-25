/*
Date: 23/06/2024

Description: This file contains implementations of functions and datatypes related to events.

Notes: x
*/

#include <memory>
#include <string>
#include <typeinfo>
#include "../include/application.hpp"
#include "../include/event.hpp"
#include "../include/globals.hpp"
#include "../include/gui.hpp"

namespace Chess
{
        namespace EventSystem
        {
        // Event
                /*
                Compares two events.
                */
                bool operator!=(const Event& lhs, const Event& rhs)
                {
                        return typeid(lhs) != typeid(rhs);
                }

                /*
                Converts the event to a string.
                */
                Event::operator std::string() const
                {
                        return m_name;
                }

        // Application Start Event
                /*
                Starts the application.
                */
                ApplicationStartEvent::ApplicationStartEvent()
                {
                        // Set the name of the event
                        m_name = "Application Start Event";

                        // Log application start event was created
                        LOG_INFO("{} created.", m_name);
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
                        // Set the name of the event
                        m_name = "Application Main Menu Event";

                        // Log application start event was created
                        LOG_INFO("{} created.", m_name);
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
                        // Set the name of the event
                        m_name = "Application Help Menu Event";

                        // Log application start event was created
                        LOG_INFO("{} created.", m_name);
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
                        // Set the name of the event
                        m_name = "Application End Event";

                        // Log application start event was created
                        LOG_INFO("{} created.", m_name);
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
                        // Set the name of the event
                        m_name = "Application Exit Event";

                        // Log application start event was created
                        LOG_INFO("{} created.", m_name);
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