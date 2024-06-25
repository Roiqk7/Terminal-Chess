/*
Date: 20/06/2024

Description: This file defines functions related to event handling.

Notes: x
*/

#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include <memory>
#include <queue>
#include <stack>
#include "event.hpp"
#include "globals.hpp"

namespace Chess
{
        namespace EventSystem
        {
                class EventHandler
                {
                public: // Methods
                // Destructor
                        ~EventHandler();
                // Singleton
                        static EventHandler& getInstance();
                        EventHandler(const EventHandler&) = delete;
                        EventHandler& operator=(const EventHandler&) = delete;
                // Event Handling
                        void submit(std::shared_ptr<Event> event);
                        void processEvents();
                        void undo();
                private: // Variables
                        std::unique_ptr<Event> m_currentEvent;
                        std::queue<std::unique_ptr<Event>> m_eventQueue;
                        std::stack<std::unique_ptr<Event>> m_eventStack;
                protected: // Constructors
                        EventHandler();
                };
        }
}

#endif // !EVENT_HANDLER_HPP