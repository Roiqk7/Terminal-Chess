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
        // Application
                void displayMainMenu();                                         // Display the main menu
                void displayControlsBar(const Globals::GameState& state);       // Display the controls bar
        // Gameplay
                void displayBoard(const Globals::FEN& fen);                     // Display the chess board
                void displayTile(const Globals::Coordinate& coordinate,
                        const Globals::FEN& fenChar);                           // Display a tile with(out) a piece on the board
                void displayGameOverMenu(const Globals::Color& winner);         // Display the game over menu
        // Messages
                void displayMessage(const std::string& message);                // Display a message
                void displayErrorMessage(const std::string& errorMessage);      // Display an error message
        // Banners
                void displayGraphics(const std::string& filePath);                // Display a banner
        // Utility
                void getDimensions();                                           // Get the dimensions of the terminal
                void setDimensions(const size_t& width, const size_t& height);  // Set the dimensions of the terminal
                void addNewLine(const int& count);                              // Add a new line(s) to the console
                void addHeaderSpace();                                          // Add a header space
                void clearScreen();                                             // Clear the screen
        }
}

#endif // !GUI_HPP