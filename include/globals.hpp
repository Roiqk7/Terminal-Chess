/*
Date: 20/06/2024

Description:

Notes: x
*/

#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <string>

namespace Chess
{
        namespace Globals
        {
                namespace Constants
                {
                // Gameplay
                        // Chess board
                        const size_t BOARD_ARRAY_SIZE = 64;                     // Number of elements in the board array
                // GUI
                        // ANSI color codes
                        const std::string RESET_COLOR = "\033[0m";              // Reset color
                        const std::string WHITE_PIECE_COLOR = "\033[97m";       // Bright white for pieces
                        const std::string BLACK_PIECE_COLOR = "\033[30m";       // Black for pieces
                        const std::string WHITE_TILE_COLOR = "\033[48;5;230m";  // Light gray background for white tiles
                        const std::string BLACK_TILE_COLOR = "\033[48;5;52m";   // Dark red background for black tiles;
                }

                enum class GameState                                            // Enum representing the state of the game
                {
                        MainMenu, Game, GameOver
                };

                enum class Color                                                // Enum representing the color of a piece or player
                {
                        None = 0, White, Black
                };

                struct Coordinate
                {
                        int file;                                               // File (column) of the coordinate (0-7) (a-h)
                        int rank;                                               // Rank (row) of the coordinate (0-7) (1-8)
                };

                using FEN = std::string;                                        // FEN string representing the state of the board

        // GUI
                // GUI Dimensions
                size_t GUI_WIDTH = 64;                                          // Width of the GUI
                size_t GUI_HEIGHT = 64;                                         // Height of the GUI
        }
}

#endif // !GLOBALS_HPP