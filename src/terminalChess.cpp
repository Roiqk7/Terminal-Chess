/*
Date: 21/06/2024

Description: This is the entry point of the program. It contains the main function.

Notes: x
*/

#include "../include/flowControl.hpp"
#include "../include/globals.hpp"

int main()
{
        // Set the log level
        SET_LOG_LEVEL_INFO();

        // Start the main application loop
        Chess::FlowControl::mainApplicationLoop();
        return 0;
}