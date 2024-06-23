/*
Date: 23/06/2024

Description: This file implements functions related to event handling.

Notes: x
*/

#include <string>
#include "../include/event.hpp"
#include "../include/eventHandler.hpp"
#include "../include/inputHandler.hpp"
#include "../include/globals.hpp"

namespace Chess
{
        namespace EventHandler
        {
                /*
                Handles an event.

                @param input The input which triggered the event
                @param gameState The game in which the event was triggered

                @return The event attributed by the event handler
                */
                Event::Event handleEvent(const char& input, Globals::GameState gameState)
                {
                        // Check if the input is valid
                        if (!isInputValid(input, gameState))
                        {
                                // TODO: handle invalid input
                        }

                        // Determine the event
                        return determineEvent(input, gameState);
                }

                /*
                Checks if the input is valid.

                @param input The input to check
                @param gameState The game in which the input was triggered

                @return True if the input is valid, false otherwise
                */
                bool isInputValid(const char& input, Globals::GameState gameState)
                {
                        // Check if the input is valid
                        return InputHandler::validateUserInput(input, gameState);
                }

                /*
                Determines the event based on the input.

                @param input The input which triggered the event
                @param gameState The game in which the event was triggered

                @return The event attributed by the event handler
                */
                Event::Event determineEvent(const char input, Globals::GameState gameState)
                {
                        // Create an event
                        Event::Event event(input, gameState);

                        // Determine the event
                        switch (gameState)
                        {
                                case Globals::GameState::MainMenu:
                                        switch (input)
                                        {
                                                case 'p':
                                                        //event.setNextState(Globals::GameState::GameModeMenu);
                                                        break;
                                                case 'h':
                                                        //event.setNextState(Globals::GameState::HelpMenu);
                                                        break;
                                                case 'c':
                                                        //event.setNextState(Globals::GameState::Credits);
                                                        break;
                                                case 'q':
                                                        //event.setNextState(Globals::GameState::Exit);
                                                        break;
                                                default:
                                                        LOG_ERROR("Invalid input.");
                                                        return Event::Event('\0', Globals::GameState::Invalid);
                                        }

                                        break;
                                case Globals::GameState::Credits:

                                        break;
                                case Globals::GameState::HelpMenu:

                                        break;
                                case Globals::GameState::GameModeMenu:

                                        break;
                                case Globals::GameState::DifficultyMenu:

                                        break;
                                case Globals::GameState::PauseMenu:

                                        break;
                                case Globals::GameState::SaveGame:

                                        break;
                                case Globals::GameState::LoadGame:

                                        break;
                                case Globals::GameState::GameOver:

                                        break;
                                default:
                                        LOG_ERROR("Invalid game state.");
                                        return Event::Event('\0', Globals::GameState::Invalid);
                        }

                        return event;
                }
        }
}