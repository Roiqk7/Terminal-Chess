/*
Date: 20/06/2024

Description: This file implements functions which create the application.

Notes: x
*/

#include "../include/application.hpp"
#include "../include/event.hpp"
#include "../include/eventHandler.hpp"
#include "../include/globals.hpp"
#include "../include/gui.hpp"
#include "../include/inputHandler.hpp"
#include "../include/tool.hpp"

namespace Chess
{
        namespace application
        {
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

                        // Start the event chain reaction
                        EventSystem::EventHandler::getInstance().submit(
                                std::make_unique<EventSystem::ApplicationMainMenuEvent>());
                }

                /*
                Handles the main menu.
                */
                void mainMenu()
                {
                        // Display main menu banner
                        GUI::displayMainMenu();

                        // Get user input
                        char input;
                        input = InputHandler::getUserInput(
                                "Enter your choice:");

                        // Process user input
                        switch (input)
                        {
                                case 'h':
                                        // Display the help menu
                                        EventSystem::EventHandler::getInstance().submit(
                                                std::make_unique<
                                                        EventSystem::ApplicationHelpMenuEvent>());
                                        break;
                                case 'q':
                                        // Quit the application
                                        EventSystem::EventHandler::getInstance().submit(
                                                std::make_unique<
                                                        EventSystem::ApplicationEndEvent>());
                                        break;
                                default:
                                        // Invalid input
                                        EventSystem::EventHandler::getInstance().submit(
                                                std::make_unique<
                                                        EventSystem::ApplicationMainMenuEvent>());
                        }
                }

                /*
                Handles the help menu.
                */
                void helpMenu()
                {
                        // Display the help menu
                        GUI::displayHelpMenu();

                        // Get user input
                        char input;
                        input = InputHandler::getUserInput(
                                "Enter your choice:");

                        // Process user input
                        switch (input)
                        {
                                case 'q':
                                        // Return to the main menu
                                        EventSystem::EventHandler::getInstance().undo();
                                        break;
                                default:
                                        // Invalid input
                                        EventSystem::EventHandler::getInstance().submit(
                                                std::make_unique<
                                                        EventSystem::ApplicationHelpMenuEvent>());
                        }
                }

                /*
                Ends the application.
                */
                void endApplication()
                {
                        // Display the ending
                        GUI::displayEnding();

                        // Switch the run flag to false
                        EventSystem::EventHandler::getInstance().run = false;

                        // Log application end
                        LOG_INFO("Application ended.");
                }

                /*
                Exits the application.
                */
                void exitApplication()
                {
                        // Log application exit
                        LOG_INFO("Application exited.");

                        // Exit the application
                        exit(0);
                }
        }
}