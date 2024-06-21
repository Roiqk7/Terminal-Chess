/*
Date: 21/06/2024

Description: This file defines functions which provide the GUI for the application.

Notes: x
*/

#ifndef GUI_HPP
#define GUI_HPP

#include <string>
#include "chessBoard.hpp"
#include "chessPieces.hpp"
#include "globals.hpp"

namespace Chess
{
        namespace GUI
        {
                namespace Constants
                {
                        // TODO: Add graphics constants
                }
        // Application
                void displayMainMenu();                                         // Display the main menu
        // Gameplay
                void displayBoard(const Globals::FEN& fen);                     // Display the chess board
                void displayTile(const Globals::Coordinate& coordinate,
                        const Globals::FEN& fenChar);                           // Display a tile with(out) a piece on the board
                void displayGameOverMenu(const Globals::Color& winner);         // Display the game over menu
        // Messages
                void displayMessage(const std::string& message);                // Display a message
        }
}

#endif // !GUI_HPP