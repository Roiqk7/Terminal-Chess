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

namespace Chess
{
        namespace EventSystem
        {
                class Event
                {
                public:
                        virtual ~Event() = default;
                        virtual void execute() = 0;
                        friend bool operator!=(const Event& lhs, const Event& rhs);
                };

                class ApplicationStartEvent : public Event
                {
                public: // Methods
                        ApplicationStartEvent();
                        void execute() override;
                };

                class ApplicationMainMenuEvent : public Event
                {
                public: // Methods
                        ApplicationMainMenuEvent();
                        void execute() override;
                };

                class ApplicationHelpMenuEvent : public Event
                {
                public: // Methods
                        ApplicationHelpMenuEvent();
                        void execute() override;
                };

                class ApplicationEndEvent : public Event
                {
                public: // Methods
                        ApplicationEndEvent();
                        void execute() override;
                };

                class ApplicationExitEvent : public Event
                {
                public: // Methods
                        ApplicationExitEvent();
                        void execute() override;
                };
        }
}

#endif // !EVENT_HPP