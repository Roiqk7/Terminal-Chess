/*
Date: 23/06/2024

Description: This file implements functions used to validate user input.

Notes: x
*/

#include <algorithm>
#include <string>
#include <vector>
#include "../include/globals.hpp"
#include "../include/validator.hpp"

namespace Chess
{
        namespace Validator
        {
                /*
                Determines if the input is valid for the game state.

                @param input The input to validate
                @param gameState The game state in which the input was triggered

                @return True if the input is valid, false otherwise

                Note: Does not validate Gameplay input.
                */
                bool validateGameState(const std::string& input,
                        const Globals::GameState gameState)
                {
                        // Vector of valid inputs
                        std::vector<std::string> validInputs;

                        // Check valid input based on the game state
                        // Find out more about valid inputs in docs/gameStates.md
                        switch (gameState)
                        {
                                case Globals::GameState::MainMenu:
                                        validInputs = {"p", "play", "h", "help", "q", "quit", "c", "credits"};
                                        if (std::find(validInputs.begin(), validInputs.end(), input)
                                                != validInputs.end())
                                        {
                                                return true;
                                        }
                                        break;
                                case Globals::GameState::Credits:
                                        validInputs = {"q", "quit"};
                                        if (std::find(validInputs.begin(), validInputs.end(), input)
                                                != validInputs.end())
                                        {
                                                return true;
                                        }
                                        break;
                                case Globals::GameState::HelpMenu:
                                        validInputs = {"q", "quit"};
                                        if (std::find(validInputs.begin(), validInputs.end(), input)
                                                != validInputs.end())
                                        {
                                                return true;
                                        }
                                        break;
                                case Globals::GameState::GameModeMenu:
                                        validInputs = {"s", "single", "singleplayer", "single-player", "m", "multi", "multiplayer", "q", "quit"};
                                        if (std::find(validInputs.begin(), validInputs.end(), input)
                                                != validInputs.end())
                                        {
                                                return true;
                                        }
                                        break;
                                case Globals::GameState::DifficultyMenu:
                                        validInputs = {"e", "easy", "m", "medium", "h", "hard", "q", "quit"};
                                        if (std::find(validInputs.begin(), validInputs.end(), input)
                                                != validInputs.end())
                                        {
                                                return true;
                                        }
                                        break;
                                case Globals::GameState::PauseMenu:
                                        validInputs = {"r", "resume", "s", "save", "l", "load", "q", "quit"};
                                        if (std::find(validInputs.begin(), validInputs.end(), input)
                                                != validInputs.end())
                                        {
                                                return true;
                                        }
                                        break;
                                case Globals::GameState::SaveGame:
                                        validInputs = {"1", "2", "3", "q", "quit"};
                                        if (std::find(validInputs.begin(), validInputs.end(), input)
                                                != validInputs.end())
                                        {
                                                return true;
                                        }
                                        break;
                                case Globals::GameState::LoadGame:
                                        validInputs = {"1", "2", "3", "q", "quit"};
                                        if (std::find(validInputs.begin(), validInputs.end(), input)
                                                != validInputs.end())
                                        {
                                                return true;
                                        }
                                        break;
                                case Globals::GameState::GameOver:
                                        validInputs = {"r", "restart", "q", "quit"};
                                        if (std::find(validInputs.begin(), validInputs.end(), input)
                                                != validInputs.end())
                                        {
                                                return true;
                                        }
                                        break;
                                default:
                                        LOG_ERROR("Invalid game state.");
                                        return false;
                        }

                        return false;
                }
        }
}