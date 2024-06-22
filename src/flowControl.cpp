/*
Date: 20/06/2024

Description: This file implements functions which control the flow of the program.

Notes: x
*/

#include "../include/flowControl.hpp"
#include "../include/globals.hpp"
#include "../include/gui.hpp"
#include "../include/tool.hpp"

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
                        // Display the intro
                        // GUI::displayIntro();

                        // Log application start
                        LOG_INFO("Application started.");
                }

                /*
                This is where the user will interact with the application. The
                application will jump off to different parts of the code based
                on the user's input and then return here until the user decides
                to exit the application.
                */
                void mainMenuLoop()
                {
                        // Display main menu banner
                        // GUI::displayMainMenu();

                        // Clear the screen
                        // GUI::clearScreen();
                }

                /*
                Ends the application.
                */
                void endApplication()
                {
                        // Display the ending
                        // GUI::displayEnding();

                        // Log application end
                        LOG_INFO("Application ended.");

                        // Clear the screen
                        // GUI::clearScreen();
                }
        }
}