/*
Date: 23/06/2024

Description: This file implements the Event Handler class.

Notes: Based on the Command Pattern. More in docs/resources.md
*/

#include <memory>
#include <queue>
#include <stack>
#include <string>
#include "../include/event.hpp"
#include "../include/eventHandler.hpp"
#include "../include/globals.hpp"

namespace Chess
{
        namespace EventSystem
        {
                /*
                Destructor
                */
                EventHandler::~EventHandler()
                {
                        // Ending scene
                }

                /*
                Get the instance of the EventHandler

                @return The instance of the EventHandler
                */
                EventHandler& EventHandler::getInstance()
                {
                        static EventHandler instance;
                        return instance;
                }

                /*
                Submit an event to the invoker

                @param event The event to submit
                */
                void EventHandler::submit(std::unique_ptr<Event> event)
                {
                        m_eventQueue.push(event);
                }


                /*
                Process the events in the queue
                */
                void EventHandler::processEvents()
                {
                        // For each event in the queue
                        while (!m_eventQueue.empty())
                        {
                                // Get the event
                                std::unique_ptr<Event> event = std::move(m_eventQueue.front());
                                m_eventQueue.pop();

                                // Execute the event
                                event->execute();

                                // Add the event to the recent events
                                m_recentEvents.push_back(std::move(event));
                        }

                        // Handle the recent events
                        handleRecentEvents();
                }

                /*
                Undo the last event
                */
                void EventHandler::undo()
                {
                        // If there are no recent events
                        if (m_recentEvents.size() < 2)
                        {
                                // Log suspicious behaviour
                                LOG_WARN("No events to undo");

                                // Return
                                return;
                        }

                        // Submit the event before the undo
                        // -2 because [..., eventWeWant, eventWeDontWant, undoEvent]
                        submit(std::move(m_recentEvents[m_recentEvents.size() - 2]));
                }

                /*
                Handle the recent events
                */
                void EventHandler::handleRecentEvents()
                {
                        // While the number of recent events is greater than the maximum
                        while (m_recentEvents.size() > m_maxRecentEvents)
                        {
                                // Pop the oldest event
                                m_recentEvents.pop_front();
                        }
                }
        }
}