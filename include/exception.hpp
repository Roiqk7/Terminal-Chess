/*
Date: 21/06/2024

Description: This file contains declarations of exceptions used in the program.

Notes: x
*/

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

namespace Chess
{
        namespace Exception
        {
        // Classes
                class RunTimeException : public std::exception
                {
                public:
                // Constructors
                        RunTimeException(const std::string& message);
                // Methods
                        virtual const char* what() const noexcept override;
                private:
                // Variables
                        std::string message;
                };

                class InvalidInputException : public RunTimeException
                {
                public:
                // Constructors
                        InvalidInputException(const std::string& message);
                // Methods
                        virtual const char* what() const noexcept override;
                private:
                // Variables
                        std::string message;
                };
        // Functions
                void logException(const std::string& message);
        }
}

#endif // !EXCEPTION_H