/*
Date: 20/06/2024

Description: This file implements functions which handle individual chess game.

Notes: By game we mean the entire application, not just the chess game.
*/

#include <fstream>
#include <string>
#include "../include/chessLibrary.hpp"
#include "../include/gameHandler.hpp"
#include "../include/tool.hpp"

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
                        // Open the file
                        std::ofstream file("data/saveSlot" + std::to_string(saveSlot) + ".txt");

                        // Write the FEN string to the file
                        file << fen;

                        // Close the file
                        file.close();
                }

                /*
                Load a saved game

                @param saveSlot: The slot from which to load the game.
                */
                void loadGame(const int saveSlot)
                {
                        // Open the file
                        std::ifstream file("data/saveSlot" + std::to_string(saveSlot) + ".txt");

                        // Read the FEN string from the file
                        std::string fen;
                        file >> fen;

                        // Close the file
                        file.close();

                        // Set the current game to the loaded game
                        std::ofstream file2("data/currGame.txt");

                        // Write the FEN string to the file
                        file2 << fen;

                        // Close the file
                        file2.close();
                }
        }
}