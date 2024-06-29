/*
Date: 20/06/2024

Description: This file implements functions which handle individual chess game.

Notes: By game we mean the entire application, not just the chess game.
*/

#include "../include/chessLibrary.hpp"
#include "../include/gameHandler.hpp"

namespace Chess
{
        namespace GameHandler
        {
                /*
                Makes sure the game proceeds as expected

                @param board: The chess board.
                */
                void mainGameLoop(chess::Board& board)
                {
                        // TODO: Implement the main game loop
                }

                /*
                Create a new game

                @param fen: The FEN string representing the board state. If empty, the default starting position is used.

                @return: The chess board.
                */
                chess::Board startGame(const std::string& fen)
                {
                        chess::Board board;
                        Chess::IChessLibrary::setupBoard(board, fen);
                        return board;
                }

                /*
                Save the current game

                @param fen: The FEN string representing the board state.
                @param saveSlot: The slot in which to save the game.
                */
                void saveGame(const std::string& fen, const int saveSlot)
                {
                        // TODO: Implement saving the game
                }

                /*
                Load a saved game

                @param saveSlot: The slot from which to load the game.
                */
                void loadGame(const int saveSlot)
                {
                        // TODO: Implement loading a saved game
                }
        }
}