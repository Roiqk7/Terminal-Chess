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
                /*
                        while (true)
                        {
                                // Display main menu banner
                                GUI::displayMainMenu();

                                std::string input;
                                input = getUserInput(Globals::GameStates::MAIN_MENU);

                                AppEvent event = getEvent(input, Globals::GameStates::MAIN_MENU);

                                if (event == AppEvent::EXIT)
                                {
                                        break;
                                }
                                else if (event == AppEvent::NEW_GAME)
                                {
                                        // Start a new game
                                        Game::startNewGame();
                                }
                                ...
                                else
                                {
                                        // Invalid input
                                        GUI::displayInvalidInput();
                                }
                        }
                */
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