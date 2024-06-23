/*
Date: 23/06/2024

Description: This file defines functions used to validate user input.

Notes: x
*/

#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP

#include <string>
#include "globals.hpp"

namespace Chess
{
        namespace Validator
        {
                bool validateGameState(const std::string& input,
                        const Globals::GameState gameState);                    // Determines if the input is valid for the game state
        }
}

#endif // !VALIDATOR_HPP