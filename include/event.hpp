/*
Date: 23/06/2024

Description: This file contains functions and datatypes related to events.

Notes: x
*/

#ifndef EVENT_HPP
#define EVENT_HPP

#include <memory>
#include <string>
#include <vector>
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
                        virtual std::unique_ptr<Event> clone() const = 0;
                        friend bool operator!=(const Event& lhs, const Event& rhs);
                        std::string getName() const;
                protected:
                        std::string m_name;
                };

                class ExceptionEvent : public Event
                {
                public: // Methods
                        ExceptionEvent(const std::vector<std::string>& message);
                        ExceptionEvent(const std::vector<std::string>& message,
                                const bool simple);
                        void execute() override;
                        std::unique_ptr<Event> clone() const override;
                private: // Variables
                        std::vector<std::string> m_message;
                        bool m_simple;
                };

                class NullEvent : public Event
                {
                public: // Methods
                        NullEvent();
                        void execute() override;
                        std::unique_ptr<Event> clone() const override;
                };

                class ApplicationStartEvent : public Event
                {
                public: // Methods
                        ApplicationStartEvent();
                        void execute() override;
                        std::unique_ptr<Event> clone() const override;
                };

                class ResetGUIEvent : public Event
                {
                public: // Methods
                        ResetGUIEvent();
                        void execute() override;
                        std::unique_ptr<Event> clone() const override;
                };

                class ApplicationMainMenuEvent : public Event
                {
                public: // Methods
                        ApplicationMainMenuEvent();
                        void execute() override;
                        std::unique_ptr<Event> clone() const override;
                };

                class ApplicationHelpMenuEvent : public Event
                {
                public: // Methods
                        ApplicationHelpMenuEvent();
                        void execute() override;
                        std::unique_ptr<Event> clone() const override;
                };

                class ApplicationCreditsEvent : public Event
                {
                public: // Methods
                        ApplicationCreditsEvent();
                        void execute() override;
                        std::unique_ptr<Event> clone() const override;
                };

                class ApplicationEndEvent : public Event
                {
                public: // Methods
                        ApplicationEndEvent();
                        void execute() override;
                        std::unique_ptr<Event> clone() const override;
                };

                class ApplicationExitEvent : public Event
                {
                public: // Methods
                        ApplicationExitEvent();
                        void execute() override;
                        std::unique_ptr<Event> clone() const override;
                };
        }
}

#endif // !EVENT_HPP