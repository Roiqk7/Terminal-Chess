/*
Date: 22/06/2024

Description: This file implements the interface with the chess library.

Notes: x
*/

#include <string>
#include <vector>
#include "../include/chessLibrary.hpp"
#include "../lib/chess-library/include/chess.hpp"

namespace Chess
{
        namespace IChessLibrary
        {
                /*
                Initializes the chess board with a given FEN string or the default starting position if no FEN is provided.

                @param board: The chess board to be initialized.
                @param fen: The FEN string representing the board state. If empty, the default starting position is used.
                */
                void setupBoard(chess::Board& board, const std::string& fen)
                {
                        board.setFen(fen);
                }

                /*
                Returns the FEN string of the current board state, including castling rights, whose move it is, etc.

                @param board: The chess board.

                @return: The FEN string of the current board state.
                */
                std::string getBoardFEN(const chess::Board& board)
                {
                        return board.getFen();
                }

                /*
                Resets the board to the initial starting position.

                @param board: The chess board to be reset.
                */
                void resetBoard(chess::Board& board)
                {
                        board.setFen(chess::constants::STARTPOS);
                }

                /*
                Makes a move on the board. The move should be specified in a format understood by the chess library.

                @param board: The chess board.
                @param move: The move to be made.
                */
                void makeMove(chess::Board& board, const chess::Move& move)
                {
                        board.makeMove(move);
                }

                /*
                Returns true if the current player is in check.

                @param board: The chess board.

                @return: Paired game reason reason and game result.
                */
                std::pair<chess::GameResultReason, chess::GameResult> getGameStatus(const chess::Board& board)
                {
                        return board.isGameOver();
                }

                /*
                Returns true if the current player is in check.

                @param board: The chess board.

                @return: True if the current player is in check, false otherwise.
                */
                bool isCheck(const chess::Board& board)
                {
                        return board.inCheck();
                }

                /*
                Returns true if the game is over.

                @param board: The chess board.

                @return: True if the game is over, false otherwise.
                */
                bool isGameOver(const chess::Board& board)
                {
                        return board.isGameOver().second != chess::GameResult::NONE;
                }
        }
}