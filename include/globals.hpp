/*
Date: 20/06/2024

Description:

Notes: x
*/

#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <string>

#ifdef DEVELOPMENT
// Include the spdlog library for logging
#include <spdlog/spdlog.h>
// Macro for development logging
#define LOG_TRACE(...) spdlog::trace(__VA_ARGS__)
#define LOG_INFO(...) spdlog::info(__VA_ARGS__)
#define LOG_WARN(...) spdlog::warn(__VA_ARGS__)
#define LOG_ERROR(...) spdlog::error(__VA_ARGS__)
#else
// Define macros as no-operation if not in development mode
#define LOG_TRACE(...) (void)0
#define LOG_INFO(...) (void)0
#define LOG_WARN(...) (void)0
#define LOG_ERROR(...) (void)0
#endif

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
                extern size_t GUI_WIDTH;                                        // Width of the GUI (defined in gui.cpp)
                extern size_t GUI_HEIGHT;                                       // Height of the GUI (defined in gui.cpp)
        }
}

#endif // !GLOBALS_HPP