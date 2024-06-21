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
                void displayIntro();                                            // Display the intro
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
                void displayGraphics(const std::string& filePath);              // Display graphics from a file
                void displayGraphics(const std::vector<std::string>& graphics); // Display graphics from a vector of strings
        // Header and footer
                void displayHeader();                                           // Display the header
                std::vector<std::string> mergeHeaders();                        // Merge the left and right headers
                void displayFooter();                                           // Display the footer
                std::vector<std::string> mergeFooters();                        // Merge the left and right footers
                std::vector<std::string> merge(const std::vector<std::string>&
                        left, const std::vector<std::string>& right,
                        const size_t& width, const std::string& filler);        // Merge two vectors of strings
        // Utility
                void getDimensions();                                           // Get the dimensions of the terminal
                void setDimensions(const size_t& width, const size_t& height);  // Set the dimensions of the terminal
                void addNewLine(const int& count);                              // Add a new line(s) to the console
                void clearScreen();                                             // Clear the screen
        }
}

#endif // !GUI_HPP