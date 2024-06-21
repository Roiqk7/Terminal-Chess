/*
Date: 21/06/2024

Description: This file contains implementations of exceptions used in the program.

Notes: x
*/

#include "../include/exception.hpp"

#ifdef DEVELOPMENT
#include "spdlog/spdlog.h"
#endif

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
                {
                        this->message = message;
                        logException(message);
                }

                /*
                Get the exception message.
                */
                const char* RunTimeException::what() const noexcept
                {
                        return message.c_str();
                }
        // Methods

                /*
                Log an exception.
                */
                void logException(const std::string& message)
                {
                        #ifdef DEVELOPMENT
                        spdlog::error(message);
                        #endif
                }
        }
}