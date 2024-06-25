/*
Date: 20/06/2024

Description: This file defines functions related to event handling.

Notes: x
*/

#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include <deque>
#include <memory>
#include <queue>
#include "event.hpp"
#include "globals.hpp"

namespace Chess
{
        namespace EventSystem
        {
                class EventHandler
                {
                public: // Variables
                        bool run;
                public: // Methods
                // Destructor
                        ~EventHandler();
                // Singleton
                        static EventHandler& getInstance();
                        EventHandler(const EventHandler&) = delete;
                        EventHandler& operator=(const EventHandler&) = delete;
                // Event Handling
                        void submit(std::unique_ptr<Event> event);
                        void processEvents();
                        void undo();
                private: // Variables
                        const size_t m_maxRecentEvents = 10;
                        std::queue<std::unique_ptr<Event>> m_eventQueue;
                        std::deque<std::unique_ptr<Event>> m_recentEvents;
                private: // Methods
                        void handleRecentEvents();
                protected: // Constructors
                        EventHandler();
                };
        }
}

#endif // !EVENT_HANDLER_HPP