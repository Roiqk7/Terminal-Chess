/*
Date: 20/06/2024

Description: This file implements functions which control the flow of the program.

Notes: x
*/

#include "../include/event.hpp"
#include "../include/eventHandler.hpp"
#include "../include/flowControl.hpp"
#include "../include/globals.hpp"
#include "../include/gui.hpp"
#include "../include/inputHandler.hpp"
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
                        // Log application start
                        LOG_INFO("Application started.");

                        // Initialize the GUI
                        GUI::initGUI();

                        // Display the intro
                        GUI::displayIntro();
                }

                /*
                This is where the user will interact with the application. The
                application will jump off to different parts of the code based
                on the user's input and then return here until the user decides
                to exit the application.
                */
                void mainMenuLoop()
                {
                        while (true)
                        {
                                // Display main menu banner
                                GUI::displayMainMenu();

                                // Get user input
                                char input;
                                input = InputHandler::getUserInput(
                                        "Enter your choice:");

                                // Validate user input
                                if (!InputHandler::validateUserInput(input,
                                        Globals::GameState::MainMenu))
                                {
                                        continue;
                                }

                                // Determine event
                                Event::Event event = EventHandler::handleEvent(
                                        input, Globals::GameState::MainMenu);

                                // Handle event
                                if (event == Globals::Event::Exit)
                                {
                                        break;
                                }
                                // Handle non-exit event
                                else
                                {
                                        // TODO: handle event
                                }
                        }
                }

                /*
                Ends the application.
                */
                void endApplication()
                {
                        // Display the ending
                        GUI::displayEnding();

                        // Log application end
                        LOG_INFO("Application ended.");
                }
        }
}