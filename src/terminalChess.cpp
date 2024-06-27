/*
Date: 21/06/2024

Description: This is the entry point of the program. It contains the main function.

Notes: x
*/

#include "../include/application.hpp"
#include "../include/globals.hpp"

using namespace Chess::application;

int main()
{
        // Set the log level
        SET_LOG_LEVEL_TRACE();

        // Start the application
        initApplication();

        // Run the application
        runApplication();

        return 0;
}