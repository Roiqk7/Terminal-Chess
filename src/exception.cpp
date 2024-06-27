/*
Date: 21/06/2024

Description: This file contains implementations of exceptions used in the program.

Notes: x
*/

#include <exception>
#include <string>
#include "../include/event.hpp"
#include "../include/eventHandler.hpp"
#include "../include/exception.hpp"
#include "../include/globals.hpp"

namespace Chess
{
        namespace Exception
        {
        // Classes
        // RunTimeException
                /*
                Constructor for the runtime exception.
                */
                RunTimeException::RunTimeException(const std::string& message)
                        : message(message)
                {
                        logException(message);
                }

                /*
                Get the exception message.
                */
                const char* RunTimeException::what() const noexcept
                {
                        return message.c_str();
                }
        // InvalidInputException
                /*
                Constructor for the invalid input exception.
                */
                InvalidInputException::InvalidInputException(const std::string& message)
                        : RunTimeException(message)
                {
                        logException(message);
                }

                /*
                Get the exception message.
                */
                const char* InvalidInputException::what() const noexcept
                {
                        return message.c_str();
                }
        // TerminalSizeException
                /*
                Constructor for the terminal size exception.
                */
                TerminalSizeException::TerminalSizeException(const std::string& message, bool width, bool tooSmall)
                        : RunTimeException(message), width(width), tooSmall(tooSmall)
                {
                        logException(message, width, tooSmall);
                }

                /*
                Get the exception message.
                */
                const char* TerminalSizeException::what() const noexcept
                {
                        return message.c_str();
                }

                /*
                Log an exception.

                @param message: The message to be logged
                @param width: The width of the terminal
                @param tooSmall: Whether the terminal is too small
                */
                void TerminalSizeException::logException(const std::string& message, const bool& width, const bool& tooSmall)
                {
                        // Too small
                        if (tooSmall)
                        {
                                // Width
                                if (width)
                                {
                                        LOG_ERROR("Terminal width is too small: {}", message);
                                }
                                // Height
                                else
                                {
                                        LOG_ERROR("Terminal height is too small: {}", message);
                                }

                                LOG_INFO("Hint: Resize the terminal to a larger size.");
                        }
                        // Terminal can not be too large. The boolean value serves readability purpose.
                }
        // Functions

                /*
                Log an exception.
                */
                void logException(const std::string& message)
                {
                        LOG_ERROR("Exception: {}", message);
                }

                /*
                Handle a terminal size exception.

                @param e: The exception to be handled
                @param message: The message to be logged
                */
                void handleTerminalSizeException(const Exception::TerminalSizeException& e,
                        bool criticallySmall)
                {
                        // Log the exception
                        LOG_CRITICAL(e.what());

                        // If even the error message is too long to display, we need to display a simpler message
                        if (criticallySmall)
                        {
                                // Display the error
                                return EventSystem::EventHandler::getInstance().submit(
                                        std::make_unique<EventSystem::ExceptionEvent>(
                                                std::vector<std::string>{"Terminal too small. Resize!!!"},
                                                true));
                        }
                        // Display the error
                        return EventSystem::EventHandler::getInstance().submit(
                                std::make_unique<EventSystem::ExceptionEvent>(std::vector<std::string>{
                                        "Dear user, your terminal size is not sufficient to display the required elements.",
                                        "Please resize your terminal and restart the application."}));
                }

                /*
                Handle an exception.

                @param e: The exception to be handled
                */
                void handleException(const std::exception& e)
                {
                        // Log the exception
                        LOG_ERROR(e.what());

                        // Display the error
                        return EventSystem::EventHandler::getInstance().submit(
                                std::make_unique<EventSystem::ExceptionEvent>(std::vector<std::string>{
                                        "An error occurred. Please restart the application."}));
                }

                /*
                Handle an unknown exception.
                */

                void handleUnknownException()
                {
                        // Log the exception
                        LOG_CRITICAL("An unknown exception occurred.");

                        // Display the error
                        EventSystem::EventHandler::getInstance().submit(
                                std::make_unique<EventSystem::ExceptionEvent>(std::vector<std::string>{
                                        "An unexpected exception occurred. Application will terminate."}));

                        // Exit the application
                        EventSystem::EventHandler::getInstance().submit(
                                std::make_unique<EventSystem::ApplicationExitEvent>());
                }
        }
}