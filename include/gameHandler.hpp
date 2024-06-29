/*
Date: 20/06/2024

Description: This file defines functions which handle individual chess game.

Notes: By game we mean the entire application, not just the chess game.
*/

#ifndef GAME_HANDLER_HPP
#define GAME_HANDLER_HPP

#include "../lib/chess-library/include/chess.hpp"

namespace Chess
{
        namespace GameHandler
        {
                void mainGameLoop(chess::Board& board);                         // Makes sure the game proceeds as expected
                chess::Board startGame(const std::string& fen);                 // Create a new game
                void saveGame(const std::string& fen, const int saveSlot);      // Save the current game
                void loadGame(const int saveSlot);                              // Load a saved game
        }
}

#endif // !GAME_HANDLER_HPP