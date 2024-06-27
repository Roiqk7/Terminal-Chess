/*
Date: 20/06/2024

Description: This file defines functions which create the application.

Notes: x
*/

#ifndef FLOW_CONTROL_HPP
#define FLOW_CONTROL_HPP

#include <string>

namespace Chess
{
        namespace application
        {
                void initApplication();                                         // Initialize the application
                void runApplication();                                          // Run the application
                void startApplication();                                        // Start the application
                void restartApplication();                                      // Restart the application
                void mainMenu();                                                // Handles the main menu loop
                void helpMenu();                                                // Handles the help menu loop
                void credits();                                                 // Display the credits
                // TODO: Add rest
                void endApplication();                                          // Finish the application
                void exitApplication();                                         // Exit the application
        }
}

#endif // !FLOW_CONTROL_HPP