/*
Date: 24/06/2024

Description: This file contains class definition for the EventExecuter class.

Notes: x
*/

#ifndef EVENT_EXECUTER_HPP
#define EVENT_EXECUTER_HPP

#include <memory>
#include "event.hpp"
#include "globals.hpp"

namespace Chess
{
        namespace EventSystem
        {
                class EventExecuter
                {
                public: // Methods
                        virtual ~EventExecuter() = default;
                        virtual void handleEvent(std::unique_ptr<Event> event) = 0;
                };

                class ApplicationEventExecuter : public EventExecuter
                {
                public: // Methods
                        void handleEvent(std::unique_ptr<Event> event) override;
                };

                class GUIEventExecuter : public EventExecuter
                {
                public: // Methods
                        void handleEvent(std::unique_ptr<Event> event) override;
                };

                class GameEventExecuter : public EventExecuter
                {
                public: // Methods
                        void handleEvent(std::unique_ptr<Event> event) override;
                };
        }
}

#endif // !EVENT_EXECUTER_HPP