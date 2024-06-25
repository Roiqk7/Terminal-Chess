/*
Date: 23/06/2024

Description: This file implements the Event Handler class.

Notes: Based on the Command Pattern. More in docs/resources.md
*/

#include <condition_variable>
#include <deque>
#include <memory>
#include <mutex>
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
                        // Log the destruction of the event handler
                        LOG_INFO("Event Handler destroyed.");
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
                Wait for an event
                */
                void EventHandler::waitEvent()
                {
                        // Create a unique lock
                        std::unique_lock<std::mutex> lock(m_mutex);

                        // Wait for the condition
                        m_condition.wait(lock, [this]
                                { return !m_eventQueue.empty() || !run; });
                }

                /*
                Submit an event to the invoker

                @param event The event to submit
                */
                void EventHandler::submit(std::unique_ptr<Event> event)
                {
                        m_eventQueue.push(std::move(event));
                }


                /*
                Process the events in the queue
                */
                void EventHandler::processEventQueue()
                {
                        // DELETE
                        if (m_eventQueue.empty())
                        {
                                run = false;
                        }

                        // For each event in the queue
                        while (!m_eventQueue.empty())
                        {
                                // Get the event
                                auto event = std::move(m_eventQueue.front());

                                // Pop the event from the queue
                                m_eventQueue.pop();

                                // Execute the event
                                event->execute();

                                // Add the event to the recent events
                                addRecentEvent(std::move(event));
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

                /*
                Add an event to the recent events

                @param event The event to add
                */
                void EventHandler::addRecentEvent(std::unique_ptr<Event> event)
                {
                        // If the recent events are empty or the event is different from the last one
                        if (m_recentEvents.empty() || *m_recentEvents.back() != *event)
                        {
                                // Add the event to the recent events
                                m_recentEvents.push_back(std::move(event));
                        }
                }

                /*
                Constructor
                */
                EventHandler::EventHandler()
                        : run(true), m_eventQueue(), m_recentEvents()
                {
                        // Log the creation of the event handler
                        LOG_INFO("Event Handler created.");

                        // Submit the application start event
                        submit(std::make_unique<ApplicationStartEvent>());
                }
        }
}