/*
Date: 23/06/2024

Description: This file contains functions and datatypes related to events.

Notes: x
*/

#ifndef EVENT_HPP
#define EVENT_HPP

#include <memory>
#include <string>
#include "eventExecuter.hpp"
#include "globals.hpp"

namespace Chess
{
        namespace EventSystem
        {
                class Event
                {
                public:
                        virtual ~Event() = default;
                        virtual void execute() = 0;
                protected:
                        std::unique_ptr<EventExecuter> m_executor;
                };

                class ApplicationStartEvent : public Event
                {
                public: // Methods
                        ApplicationStartEvent(std::unique_ptr<EventExecuter> executor);
                        void execute() override;
                };
        }
}

#endif // !EVENT_HPP