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

// Macros to set log level
#define SET_LOG_LEVEL_TRACE() spdlog::set_level(spdlog::level::trace)
#define SET_LOG_LEVEL_DEBUG() spdlog::set_level(spdlog::level::debug)
#define SET_LOG_LEVEL_INFO() spdlog::set_level(spdlog::level::info)
#define SET_LOG_LEVEL_WARN() spdlog::set_level(spdlog::level::warn)
#define SET_LOG_LEVEL_ERROR() spdlog::set_level(spdlog::level::err)
#define SET_LOG_LEVEL_CRITICAL() spdlog::set_level(spdlog::level::critical)
#define SET_LOG_LEVEL_OFF() spdlog::set_level(spdlog::level::off)

#else
// Define macros as no-operation if not in development mode
#define LOG_TRACE(...) (void)0
#define LOG_INFO(...) (void)0
#define LOG_WARN(...) (void)0
#define LOG_ERROR(...) (void)0

// Define SET_LOG_LEVEL macros as no-operation if not in development mode
#define SET_LOG_LEVEL_TRACE() (void)0
#define SET_LOG_LEVEL_DEBUG() (void)0
#define SET_LOG_LEVEL_INFO() (void)0
#define SET_LOG_LEVEL_WARN() (void)0
#define SET_LOG_LEVEL_ERROR() (void)0
#define SET_LOG_LEVEL_CRITICAL() (void)0
#define SET_LOG_LEVEL_OFF() (void)0

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
                // File paths
                // Assets
                        const std::string ASSETS_PATH = "../assets/";           // Path to the assets folder
                        const std::string ERROR_BANNER_PATH = ASSETS_PATH
                                + "errorBanner.txt";                            // Path to the error banner
                        const std::string FAREWELL_PATH = ASSETS_PATH
                                + "farewell.txt";                               // Path to the farewell text
                        const std::string FOOTER_PATH = ASSETS_PATH
                                + "footer.txt";                                 // Path to the footer
                        const std::string FOOTER_LEFT_PATH = ASSETS_PATH
                                + "footerLeft.txt";                             // Path to the left footer
                        const std::string FOOTER_RIGHT_PATH = ASSETS_PATH
                                + "footerRight.txt";                            // Path to the right footer
                        const std::string GAME_OVER_BANNER_PATH = ASSETS_PATH
                                + "gameOverBanner.txt";                         // Path to the game over banner
                        const std::string HEADER_PATH = ASSETS_PATH
                                + "header.txt";                                 // Path to the header
                        const std::string HEADER_LEFT_PATH = ASSETS_PATH
                                + "headerLeft.txt";                             // Path to the left header
                        const std::string HEADER_RIGHT_PATH = ASSETS_PATH
                                + "headerRight.txt";                            // Path to the right header
                        const std::string HELP_MENU_PATH = ASSETS_PATH
                                + "helpMenu.txt";                               // Path to the help menu
                        const std::string HELP_MENU_BANNER_PATH = ASSETS_PATH
                                + "helpMenuBanner.txt";                         // Path to the help menu banner
                        const std::string MAIN_MENU_PATH = ASSETS_PATH
                                + "mainMenu.txt";                               // Path to the main menu
                        const std::string MAIN_MENU_BANNER_PATH = ASSETS_PATH
                                + "mainMenuBanner.txt";                         // Path to the main menu banner
                        const std::string USER_INPUT_SEPARATOR_PATH = ASSETS_PATH
                                + "userInputSeparator.txt";                     // Path to the user input separator
                        const std::string WELCOME_BANNER_PATH = ASSETS_PATH
                                + "welcomeBanner.txt";                          // Path to the welcome banner
                        }

                /*
                Game states influence the the relationship between the game
                and the user. Each game state has its own set of rules and
                acceptable user inputs. For more information visit the
                documentation. (docs/gameStates.md)
                */
                enum class GameState                                            // Enum representing the state of the application (game as a whole)
                {
                        MainMenu, Credits, HelpMenu, GameModeMenu,
                        DifficultyMenu, GamePlay, PauseMenu, SaveGame,
                        LoadGame, GameOver
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
        // Application
                extern GameState gameState;                                     // Current state of the application
        // GUI
                // GUI Dimensions
                extern size_t GUI_WIDTH;                                        // Width of the GUI (defined in gui.cpp)
                extern size_t GUI_HEIGHT;                                       // Height of the GUI (defined in gui.cpp)
        }
}

#endif // !GLOBALS_HPP