/*
Date: 20/06/2024

Description: This file defines functions which handle individual chess game.

Notes: By game we mean the entire application, not just the chess game.
*/

#ifndef GAME_HANDLER_HPP
#define GAME_HANDLER_HPP

namespace Chess
{
        namespace GameHandler
        {
                void mainGameLoop();                                            // Makes sure the game proceeds as expected
                void startGame();                                               // Create a new game from scratch
                void endGame();                                                 // Finish the current game
        }
}

#endif // !GAME_HANDLER_HPP