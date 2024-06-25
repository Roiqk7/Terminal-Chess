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
                        return EventSystem::EventHandler::getInstance().submit(
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

                        // Handle user input
                        switch (input)
                        {
                                // Credits
                                case 'c':
                                        return EventSystem::EventHandler::getInstance().submit(
                                                std::make_unique<EventSystem::ApplicationCreditsEvent>());
                                // We do this to make sure 'q' leaves the application
                                case 'q':
                                        // Start the game
                                        return EventSystem::EventHandler::getInstance().submit(
                                                std::make_unique<EventSystem::ApplicationEndEvent>());

                                default:
                                        // Handle "other" input
                                        break;
                        }

                        // Handle input
                        return InputHandler::handleInput(input,
                                std::make_unique<EventSystem::ApplicationMainMenuEvent>());
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

                        // Handle input
                        return InputHandler::handleInput(input,
                                std::make_unique<EventSystem::ApplicationHelpMenuEvent>());
                }

                /*
                Credits
                */
                void credits()
                {
                        // Display the credits
                        GUI::displayCredits();

                        // Get user input
                        char input;
                        input = InputHandler::getUserInput(
                                "Enter your choice:");

                        // Handle input
                        return InputHandler::handleInput(input,
                                std::make_unique<EventSystem::ApplicationCreditsEvent>());
                }

                /*
                Ends the application.
                */
                void endApplication()
                {
                        // Display the ending
                        GUI::displayEnding();

                        // Quit the application
                        return EventSystem::EventHandler::getInstance().submit(
                                std::make_unique<
                                        EventSystem::ApplicationExitEvent>());
                }

                /*
                Exits the application.
                */
                void exitApplication()
                {
                        // Switch the run flag to false
                        EventSystem::EventHandler::getInstance().run = false;

                        // Log application end
                        LOG_INFO("Application ended.");
                }
        }
}