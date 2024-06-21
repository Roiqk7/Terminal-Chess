/*
Date: 20/06/2024

Description: This file implements functions which control the flow of the program.

Notes: x
*/

#include "../include/flowControl.hpp"
#include "../include/inputHandler.hpp"

namespace Chess
{
        namespace FlowControl
        {
                /*
                Handles the main application loop.
                */
                void mainApplicationLoop()
                {
                        // Start the application
                        startApplication();

                        // Main application loop
                        mainMenuLoop();

                        // End the application
                        endApplication();
                }
        }
}