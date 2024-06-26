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
#include <typeinfo>
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
                        // Check if the event type is ExceptionEvent
                        if (typeid(*event) == typeid(ExceptionEvent))
                        {
                                m_exceptionQueue.push(std::move(event));
                        }
                        else
                        {
                                m_eventQueue.push(std::move(event));
                        }
                }


                /*
                Process the events in the queue
                */
                void EventHandler::processEventQueue()
                {
                        // First process the exception queue
                        if (!m_exceptionQueue.empty())
                        {
                                // Get the exception event
                                auto exceptionEvent = std::move(m_exceptionQueue.front());

                                // Log the exception event
                                LOG_ERROR("Exception Event: {} is now being processed.", exceptionEvent->getName());

                                // Pop the exception event from the queue
                                m_exceptionQueue.pop();

                                // Add the exception event to the recent events
                                addRecentEvent(std::move(exceptionEvent));

                                // Execute the exception event
                                m_recentEvents.back()->execute();
                        }
                        // Process regular events
                        if (!m_eventQueue.empty())
                        {
                                // Get the event
                                auto event = std::move(m_eventQueue.front());

                                // Log the event
                                LOG_TRACE("Event: {} is now being processed.", event->getName());

                                // Pop the event from the queue
                                m_eventQueue.pop();

                                // Add the event to the recent events
                                addRecentEvent(std::move(event));

                                // Execute the event
                                m_recentEvents.back()->execute();
                        }
                }

                /*
                Undo the last event
                */
                void EventHandler::undo()
                {
                        // Log that undo is being called
                        LOG_TRACE("Undoing the last event.");

                        // Check if there are any events to undo
                        if (m_recentEvents.size() <= 1)
                        {
                                // Log that there are no events to undo
                                LOG_WARN("No events to undo. Restarting the application...");

                                return init();
                        }

                        // Remove the last event from the recent events
                        m_recentEvents.pop_back();

                        // Log the size of the recent events
                        LOG_TRACE("Recent events size: {}", m_recentEvents.size());

                        // Execute the event
                        m_recentEvents.back()->execute();
                }

                /*
                Restart the event handler (and thus the application)
                */
                void EventHandler::restart()
                {
                        // Log that the application is being restarted
                        LOG_WARN("Restarting the application...");

                        // Cleanup the event handler
                        cleanup();

                        // Initialize the event handler
                        init();
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
                                // Log the event
                                LOG_TRACE("Event added to recent events: {}", event->getName());

                                // Add the event to the recent events
                                m_recentEvents.push_back(std::move(event));
                        }

                        // Handle the recent events
                        handleRecentEvents();
                }

                /*
                Initialize the event handler
                */
                void EventHandler::init()
                {
                        // Log that the event handler is being initialized
                        LOG_TRACE("Initializing the event handler.");

                        // Add the null event to the recent events to properly initialize the event handlers
                        addRecentEvent(std::make_unique<NullEvent>());
                }

                /*
                Cleanup the event handler
                */
                void EventHandler::cleanup()
                {
                        // Log that the event handler is being cleaned up
                        LOG_TRACE("Cleaning up the event handler.");

                        // Clear the recent events
                        m_recentEvents.clear();

                        // Clear the event queue
                        while (!m_eventQueue.empty())
                        {
                                m_eventQueue.pop();
                        }
                }

                /*
                Handle the recent events
                */
                void EventHandler::handleRecentEvents()
                {
                        // Log that the recent events are being handled
                        LOG_TRACE("Handling recent events:");

                        for (auto& event : m_recentEvents)
                        {
                                // Log the event
                                LOG_TRACE("Event: {}. ", event->getName());
                        }

                        // Log the size of the recent events
                        LOG_TRACE("Recent events size: {}", m_recentEvents.size());

                        // While the number of recent events is greater than the maximum
                        while (m_recentEvents.size() > m_maxRecentEvents)
                        {
                                // Pop the oldest event
                                m_recentEvents.pop_front();
                        }
                }

                /*
                Constructor
                */
                EventHandler::EventHandler()
                        : run(true),  m_eventQueue(), m_recentEvents()
                {
                        // Log the creation of the event handler
                        LOG_INFO("Event Handler created.");

                        // Initialize the event handler
                        init();
                }
        }
}