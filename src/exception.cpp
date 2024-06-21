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