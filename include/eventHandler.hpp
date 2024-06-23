/*
Date: 20/06/2024

Description: This file defines functions related to event handling.

Notes: x
*/

#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include <stack>
#include "event.hpp"
#include "globals.hpp"

namespace Chess
{
        namespace EventSystem
        {
                class EventHandler
                { // TODO: Make the constructor submit a welcome event and destructor farewell event
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
                        void redo();
                private: // Variables
                        std::queue<std::unique_ptr<Event>> m_eventQueue;
                        std::stack<std::unique_ptr<Event>> m_eventStack;
                protected: // Constructors
                        EventHandler();
                };
        }
}

#endif // !EVENT_HANDLER_HPP