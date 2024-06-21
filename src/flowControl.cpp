/*
Date: 20/06/2024

Description: This file implements functions which control the flow of the program.

Notes: x
*/

#include "../include/flowControl.hpp"
#include "../include/gui.hpp"
#include "../include/tool.hpp"

#ifdef DEVELOPMENT
#include "spdlog/spdlog.h"
#endif

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

                /*
                Starts the application.
                */
                void startApplication()
                {
                        // Display welcome banner
                        GUI::displayBanner("../assets/welcomeHeading.txt");

                        // Wait for a few seconds
                        Tool::wait(2);

                        // Log application start
                        #ifdef DEVELOPMENT
                        spdlog::info("Application started");
                        #endif
                }

                /*
                This is where the user will interact with the application. The
                application will jump off to different parts of the code based
                on the user's input and then return here until the user decides
                to exit the application.
                */
                void mainMenuLoop()
                {
                        // TODO: Implement
                }

                /*
                Ends the application.
                */
                void endApplication()
                {
                        // TODO: Implement
                }
        }
}