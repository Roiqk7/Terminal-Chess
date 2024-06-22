/*
Date: 21/06/2024

Description: This file contains implementations of exceptions used in the program.

Notes: x
*/

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
                        }
                        // Terminal can not be too large. The boolean value serves readability purpose.
                }
        // Methods

                /*
                Log an exception.
                */
                void logException(const std::string& message)
                {
                        LOG_ERROR("Exception: {}", message);
                }
        }
}