/*
Date: 20/06/2024

Description:

Notes: x
*/

#include <string>

namespace Chess
{
        namespace Globals
        {
                namespace Constants
                {
                        // Chess board
                        const size_t BOARD_ARRAY_SIZE = 64;                     // Number of elements in the board array
                        // ANSI color codes
                        const std::string RESET_COLOR = "\033[0m";              // Reset color
                        const std::string WHITE_PIECE_COLOR = "\033[97m";       // Bright white for pieces
                        const std::string BLACK_PIECE_COLOR = "\033[30m";       // Black for pieces
                        const std::string WHITE_TILE_COLOR = "\033[48;5;230m";  // Light gray background for white tiles
                        const std::string BLACK_TILE_COLOR = "\033[48;5;52m";   // Dark red background for black tiles;
                }

                enum class GameState
                {
                        MainMenu, Game, GameOver
                };

                enum class Player
                {
                        White, Black
                };

                enum class PieceType
                {
                        Pawn, Knight, Bishop, Rook, Queen, King
                };

                struct Coordinate
                {
                        int file;                                               // File (column) of the coordinate (0-7) (a-h)
                        int rank;                                               // Rank (row) of the coordinate (0-7) (1-8)
                };

                using FEN = std::string;
        }
}