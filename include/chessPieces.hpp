/*
Date: 20/06/2024

Description: This file defines everything related to chess pieces.

Notes: x
*/

#ifndef CHESS_PIECES_HPP
#define CHESS_PIECES_HPP

namespace Chess
{
        namespace Pieces
        {
                enum class PieceType                                            // Enum class to represent the type of a piece with values from 0 to 6.
                {
                        None = 0, Pawn, Knight, Bishop, Rook, Queen, King
                };

                class Piece                                                     // Class representing a chess piece
                {
                public: // Variables
                        PieceType pieceType;                                    // Type of the piece

                };
        }
}

#endif // !CHESS_PIECES_HPP