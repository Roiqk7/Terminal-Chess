/*
Date: 20/06/2024

Description: This file implements functions which create the application.

Notes: x
*/

#include "../include/application.hpp"
#include "../include/event.hpp"
#include "../include/eventHandler.hpp"
#include "../include/exception.hpp"
#include "../include/globals.hpp"
#include "../include/gui.hpp"
#include "../include/inputHandler.hpp"
#include "../include/tool.hpp"

namespace Chess
{
        namespace application
        {
                /*
                Initializes the application.
                */
                void initApplication()
                {
                        // Create the event handler
                        Chess::EventSystem::EventHandler::getInstance();

                        // Log application start
                        LOG_INFO("Application initialized.");

                        // Submit the application start event to start the application
                        EventSystem::EventHandler::getInstance()
                                .submit(std::make_unique<
                                        EventSystem::ApplicationStartEvent>());
                }

                /*
                Runs the application.
                */
                void runApplication()
                {
                        // Application loop
                        while (EventSystem::EventHandler::getInstance().run)
                        {
                                // Wait for an event
                                EventSystem::EventHandler::getInstance().waitEvent();

                                // Process event queue
                                EventSystem::EventHandler::getInstance().processEventQueue();
                        }
                }

                /*
                Starts the application.
                */
                void startApplication()
                {
                        // Catch any exceptions
                        try
                        {
                                // Initialize the GUI
                                GUI::initGUI();

                                // Display the intro
                                GUI::displayIntro();

                                // Log application start
                                LOG_INFO("Application started.");

                                // Start the event chain
                                EventSystem::EventHandler::getInstance()
                                .submit(std::make_unique<
                                        EventSystem::ApplicationMainMenuEvent>());
                        }
                        // Terminal size exception
                        catch (const Exception::TerminalSizeException &e)
                        {
                                // Handle the exception
                                return Exception::handleTerminalSizeException(e, true);
                        }
                        // Other standard exceptions
                        catch (const std::exception &e)
                        {
                                // Handle the exception
                                return Exception::handleException(e);
                        }
                        // Other exceptions
                        catch (...)
                        {
                                // Handle the exception
                                return Exception::handleUnknownException();
                        }
                }

                /*
                Restarts the application.
                */
                void restartApplication()
                {
                        // Restart the application
                        return initApplication();
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

                        // Handle user input
                        switch (input)
                        {
                                // We do this to make sure 'q' leaves the application
                                case 'q':
                                        // Start the game
                                        return EventSystem::EventHandler::getInstance().submit(
                                                std::make_unique<EventSystem::ApplicationMainMenuEvent>());

                                default:
                                        // Handle "other" input
                                        break;
                        }

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

                        // Handle user input
                        switch (input)
                        {
                                // We do this to make sure 'q' leaves the application
                                case 'q':
                                        // Start the game
                                        return EventSystem::EventHandler::getInstance().submit(
                                                std::make_unique<EventSystem::ApplicationMainMenuEvent>());

                                default:
                                        // Handle "other" input
                                        break;
                        }

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