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
                void displayGameplay();                                         // Display the gameplay
                void displayEnding();                                           // Display the ending
        // Messages
                void displayErrorMessage(const std::string& errorMessage);      // Display an error message
        // Header and footer
        // Note: Will be removed soon but need to find place for it
                void displayHeader();                                           // Display the header
                std::vector<std::string> mergeHeaders();                        // Merge the left and right headers
                void displayFooter();                                           // Display the footer
                std::vector<std::string> mergeFooters();                        // Merge the left and right footers
                std::vector<std::string> merge(const std::vector<std::string>&
                        left, const std::vector<std::string>& right,
                        const size_t& width, const std::string& filler);        // Merge two vectors of strings
        // Pattern repetition
        // Note: Will be removed soon but need to find place for it
                std::vector<std::string> repeatPattern(
                        const std::string& filePath, const size_t& count,
                        const char& delimiter);                                 // Repeat a pattern a certain number of times
        // Utility
                void getDimensions();                                           // Get the dimensions of the terminal
                void setDimensions(const size_t& width, const size_t& height);  // Set the dimensions of the terminal
                void clearScreen();                                             // Clear the screen
        }
}

#endif // !GUI_HPP