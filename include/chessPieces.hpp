/*
Date: 20/06/2024

Description: This file defines everything related to chess pieces.

Notes: x
*/

#ifndef CHESS_PIECES_HPP
#define CHESS_PIECES_HPP

#include <vector>
#include "globals.hpp"

namespace Chess
{
        namespace Pieces
        {
                enum class PieceType                                            // Enum class to represent the type of a piece with values from 0 to 6.
                {
                        None = 0, Pawn, Knight, Bishop, Rook, Queen, King
                };

                class Piece                                                     // Class representing a chess piece from which the actual pieces will be derived
                {
                public: // Variables
                        PieceType pieceType;                                    // Type of the piece
                        Globals::Color color;                                   // Color of the piece
                        Globals::Coordinate position;                           // Position of the piece on the board
                public: // Methods
                // Constructors
                        Piece();                                                // Default constructor
                        Piece(const PieceType& pieceType,
                                const Globals::Color& color,
                                const Globals::Coordinate& position);           // Constructor with all parameters
                // Game logic
                        void move(const Globals::Coordinate& newPosition);      // Move the piece to a new position
                // Getters
                        PieceType getPieceType() const;                         // Get the type of the piece
                        Globals::Color getColor() const;                        // Get the color of the piece
                        Globals::Coordinate getPosition() const;                // Get the position of the piece
                // Setters
                        void setPieceType(const PieceType& pieceType);          // Set the type of the piece
                        void setColor(const Globals::Color& color);             // Set the color of the piece
                        void setPosition(const Globals::Coordinate& position);  // Set the position of the piece
                // Utility
                        void clear();                                           // Clear all piece data
                private:
                };
        }
}

#endif // !CHESS_PIECES_HPP