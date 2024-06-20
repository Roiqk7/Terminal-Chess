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
                using PieceChar = char;

                enum class PieceType
                {
                        None = 0, Pawn, Knight, Bishop, Rook, Queen, King
                };

                class Piece
                {

                };
        }
}

#endif // !CHESS_PIECES_HPP