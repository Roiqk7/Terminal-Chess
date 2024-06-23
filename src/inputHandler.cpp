/*
Date: 20/06/2024

Description: This file implements functions which handle user input.

Notes: x
*/

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include "../include/displayer.hpp"
#include "../include/inputHandler.hpp"
#include "../include/globals.hpp"
#include "../include/gui.hpp"
#include "../include/tool.hpp"

namespace Chess
{
        namespace InputHandler
        {
                /*
                Get user input from the console.

                @param prompt: The prompt to display to the user

                @return: The user's input
                */
                std::string getUserInput(const std::string& prompt)
                {
                        std::string input;

                        // Center the prompt
                        std::string centeredPrompt = prompt;

                        // Center the prompt
                        centeredPrompt = Tool::centerString(
                                centeredPrompt, Globals::GUI_WIDTH, false);

                        // Display the prompt
                        GUI::displayString(centeredPrompt, ' ');

                        // Get the input
                        std::cin >> input;

                        // Log the input
                        LOG_TRACE("User input: " + input);

                        return input;
                }

                /*
                Validate user input.

                @param input: The user's input
                @param gameState: The current game state

                @return: True if the input is valid, false otherwise
                */
                bool validateUserInput(const std::string& input,
                        Globals::GameState gameState)
                {
                        // Check empty input
                        if (input.empty())
                        {
                                return false;
                        }

                        // Lowercase the input
                        std::string lowercaseInput;
                        lowercaseInput.resize(input.size());
                        std::transform(input.begin(), input.end(), lowercaseInput.begin(),
                                [](unsigned char c){ return std::tolower(c); });

                        // Vector of valid inputs
                        std::vector<std::string> validInputs;

                        // Check valid input based on the game state
                        // Find out more about valid inputs in docs/gameStates.md
                        switch (gameState)
                        {
                                case Globals::GameState::MainMenu:
                                        validInputs = {"p", "play", "h", "help", "q", "quit", "c", "credits"};
                                        if (std::find(validInputs.begin(), validInputs.end(), lowercaseInput) != validInputs.end())
                                        {
                                                return true;
                                        }
                                        break;
                                case Globals::GameState::Credits:
                                        validInputs = {"q", "quit"};
                                        if (std::find(validInputs.begin(), validInputs.end(), lowercaseInput) != validInputs.end())
                                        {
                                                return true;
                                        }
                                        break;
                                case Globals::GameState::HelpMenu:
                                        validInputs = {"q", "quit"};
                                        if (std::find(validInputs.begin(), validInputs.end(), lowercaseInput) != validInputs.end())
                                        {
                                                return true;
                                        }
                                        break;
                                case Globals::GameState::GameModeMenu:
                                        validInputs = {"s", "single", "singleplayer", "single-player", "m", "multi", "multiplayer", "q", "quit"};
                                        if (std::find(validInputs.begin(), validInputs.end(), lowercaseInput) != validInputs.end())
                                        {
                                                return true;
                                        }
                                        break;
                                case Globals::GameState::DifficultyMenu:
                                        validInputs = {"e", "easy", "m", "medium", "h", "hard", "q", "quit"};
                                        if (std::find(validInputs.begin(), validInputs.end(), lowercaseInput) != validInputs.end())
                                        {
                                                return true;
                                        }
                                        break;
                                case Globals::GameState::GamePlay:
                                        // TODO: Add valid inputs for game play
                                        break;
                                case Globals::GameState::PauseMenu:
                                        validInputs = {"r", "resume", "s", "save", "l", "load", "q", "quit"};
                                        if (std::find(validInputs.begin(), validInputs.end(), lowercaseInput) != validInputs.end())
                                        {
                                                return true;
                                        }
                                        break;
                                case Globals::GameState::SaveGame:
                                        validInputs = {"1", "2", "3", "q", "quit"};
                                        if (std::find(validInputs.begin(), validInputs.end(), lowercaseInput) != validInputs.end())
                                        {
                                                return true;
                                        }
                                        break;
                                case Globals::GameState::LoadGame:
                                        validInputs = {"1", "2", "3", "q", "quit"};
                                        if (std::find(validInputs.begin(), validInputs.end(), lowercaseInput) != validInputs.end())
                                        {
                                                return true;
                                        }
                                        break;
                                case Globals::GameState::GameOver:
                                        validInputs = {"r", "restart", "q", "quit"};
                                        if (std::find(validInputs.begin(), validInputs.end(), lowercaseInput) != validInputs.end())
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