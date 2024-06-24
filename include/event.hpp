/*
Date: 23/06/2024

Description: This file contains functions and datatypes related to events.

Notes: x
*/

#ifndef EVENT_HPP
#define EVENT_HPP

#include <memory>
#include <string>
#include "globals.hpp"
#include "eventExecuter.hpp"

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
                        std::shared_ptr<EventExecuter> m_executor;
                };

                // TODO: Create all the necessary concrete event classes

                class WelcomeEvent : public Event
                {
                public: // Methods
                        WelcomeEvent(std::shared_ptr<EventExecuter> executor) {}
                        void execute() override;
                };
        }
}

#endif // !EVENT_HPP