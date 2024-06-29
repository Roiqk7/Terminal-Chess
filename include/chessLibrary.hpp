/*
Date: 22/06/2024

Description: This file defines the interface with the chess library.

Notes: x
*/

#ifndef CHESS_LIBRARY_HPP
#define CHESS_LIBRARY_HPP

#include <string>
#include <vector>
#include "../lib/chess-library/include/chess.hpp"

namespace Chess
{
        namespace IChessLibrary
        {
        // Board functions
                void setupBoard(chess::Board& board,
                        const std::string& fen = chess::constants::STARTPOS);   // Initializes the chess board with a given FEN string or the default starting position if no FEN is provided.
                std::string getBoardFEN(const chess::Board& board);             // Returns the FEN string of the current board state, including castling rights, whose move it is, etc.
                void resetBoard(chess::Board& board);                           // Resets the board to the initial starting position.
        // Gameplay functions
                void makeMove(chess::Board& board, const chess::Move& move);    // Makes a move on the board. The move should be specified in a format understood by the chess library.
                // TODO generate moves for specific piece
                std::pair<chess::GameResultReason, chess::GameResult>
                        getGameStatus(const chess::Board& board);               // Returns the current game status.
                bool isCheck(const chess::Board& board);                        // Returns true if the current player is in check.
                bool isGameOver(const chess::Board& board);                     // Returns true if the game is over.
        }
}

#endif // !CHESS_LIBRARY_HPP