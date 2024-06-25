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
                Gets the name of the event.

                @return The name of the event
                */
                std::string Event::getName() const
                {
                        return m_name;
                }
        // Exception Event
                // TODO: Implement
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

                /*
                Clones the event.

                @return A clone of the event
                */
                std::unique_ptr<Event> ApplicationStartEvent::clone() const
                {
                        return std::make_unique<ApplicationStartEvent>(*this);
                }
        // Reset GUI Event
                /*
                Resets the GUI.
                */
                ResetGUIEvent::ResetGUIEvent()
                {
                        // Set the name of the event
                        m_name = "Reset GUI Event";

                        // Log application start event was created
                        LOG_INFO("{} created.", m_name);
                }

                /*
                Executes the event.
                */
                void ResetGUIEvent::execute()
                {
                        // Reset the GUI
                        GUI::getDimensions();
                }

                /*
                Clones the event.

                @return A clone of the event
                */
                std::unique_ptr<Event> ResetGUIEvent::clone() const
                {
                        return std::make_unique<ResetGUIEvent>(*this);
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

                /*
                Clones the event.

                @return A clone of the event
                */
                std::unique_ptr<Event> ApplicationMainMenuEvent::clone() const
                {
                        return std::make_unique<ApplicationMainMenuEvent>(*this);
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

                /*
                Clones the event.

                @return A clone of the event
                */
                std::unique_ptr<Event> ApplicationHelpMenuEvent::clone() const
                {
                        return std::make_unique<ApplicationHelpMenuEvent>(*this);
                }
        // Application Credits Event
                /*
                Display the credits.
                */
                ApplicationCreditsEvent::ApplicationCreditsEvent()
                {
                        // Set the name of the event
                        m_name = "Application Credits Event";

                        // Log application start event was created
                        LOG_INFO("{} created.", m_name);
                }

                /*
                Executes the event.
                */
                void ApplicationCreditsEvent::execute()
                {
                        // Display the credits
                        application::credits();
                }

                /*
                Clones the event.

                @return A clone of the event
                */
                std::unique_ptr<Event> ApplicationCreditsEvent::clone() const
                {
                        return std::make_unique<ApplicationCreditsEvent>(*this);
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

                /*
                Clones the event.

                @return A clone of the event
                */
                std::unique_ptr<Event> ApplicationEndEvent::clone() const
                {
                        return std::make_unique<ApplicationEndEvent>(*this);
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

                /*
                Clones the event.

                @return A clone of the event
                */
                std::unique_ptr<Event> ApplicationExitEvent::clone() const
                {
                        return std::make_unique<ApplicationExitEvent>(*this);
                }
        }
}