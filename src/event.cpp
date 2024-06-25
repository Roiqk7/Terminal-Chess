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
                ApplicationStartEvent::ApplicationStartEvent(std::shared_ptr<Event> self, std::unique_ptr<EventExecuter> executor)
                {
                        // Set the pointer to itself
                        m_self = self;

                        // Set the executor
                        m_executor = std::move(executor);

                        // Log application start
                        LOG_INFO("Application started.");
                }

                /*
                Executes the event.
                */
                void ApplicationStartEvent::execute()
                {
                        // Create a shared pointer to itself
                        auto self = m_self.lock();

                        // If the pointer is valid
                        if (self)
                        {
                                // Execute the event
                                m_executor->handleEvent(self);
                        }
                        else
                        {
                                // Log the failure to execute the event
                                LOG_ERROR("Failed to execute ApplicationStartEvent.");
                        }
                }
        }
}