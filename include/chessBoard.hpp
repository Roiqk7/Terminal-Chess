/*
Date: 20/06/2024

Description: This file defines everything related to the chess board.

Notes: x
*/

#ifndef CHESS_BOARD_HPP
#define CHESS_BOARD_HPP

#include <array>
#include <string>
#include <vector>
#include "../include/chessBoard.hpp"
#include "../include/chessPieces.hpp"
#include "../include/eventHandler.hpp"
#include "../include/globals.hpp"

namespace Chess
{
        namespace Board
        {
                using BoardArray = std::array<Pieces::PieceType,
                        Globals::Constants::BOARD_ARRAY_SIZE>;                  // Array representing the chess board (64 elements)

                class Board                                                     // Class representing the chess board
                {
                public: // Variables
                        BoardArray boardArray;                                  // Array representing the chess board (64 elements)
                        Globals::FEN fen;                                       // FEN string representing the current state of the board
                public: // Methods
                // Constructors
                        Board();                                                // Default constructor
                        Board(const Globals::FEN& fen);                         // Constructor with FEN string
                // Methods
                // Game logic
                        void makeMove(const EventHandler::Event& event);        // Make a move on the board
                // Setters
                        void setUpBoardWithFen(const Globals::FEN& fen);        // Set up the board with a FEN string
                // Getters
                        BoardArray getBoardArray() const;                       // Get the board array storing the current state of the board
                        Globals::FEN getFen() const;                            // Get the FEN string representing the current state of the board
                // Individual tiles
                        Pieces::PieceType getTile(
                                const Globals::Coordinate& coordinate) const;   // Get the piece on a tile
                        void setTile(const Globals::Coordinate& coordinate,
                                const Pieces::PieceType& piece);                // Set the piece on a tile
                        void clearTile(const Globals::Coordinate& coordinate);  // Clear the piece on a tile
                        bool isTileEmpty(
                                const Globals::Coordinate& coordinate) const;   // Check if a tile is empty
                // Utility
                        void clearBoard();                                      // Clear the board (empty all tiles)
                        bool isEmpty() const;                                   // Check if the board is empty
                private:
                };
        }
}

#endif // !CHESS_BOARD_HPP