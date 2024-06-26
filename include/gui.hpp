/*
Date: 21/06/2024

Description: This file defines functions which provide the GUI for the application.

Notes: x
*/

#ifndef GUI_HPP
#define GUI_HPP

#include <string>
#include "globals.hpp"

namespace Chess
{
        namespace GUI
        {
        // General
                void initGUI();                                                 // Initialize the GUI
        // Application
                void displayIntro();                                            // Display the intro
                void displayMainMenu();                                         // Display the main menu
                void displayHelpMenu();                                         // Display the help menu
                void displayCredits();                                          // Display the credits
                void displayGameplay();                                         // Display the gameplay
                void displayEnding();                                           // Display the ending
                void displayError(
                        const std::vector<std::string>& errorMessage);         // Display an error
                void displaySimpleError(
                        const std::string& errorMessage);                       // Display a simple error
        // Utility
                void getDimensions();                                           // Get the dimensions of the terminal
                void setDimensions(const size_t& width, const size_t& height);  // Set the dimensions of the terminal
                void clearScreen();                                             // Clear the screen
        }
}

#endif // !GUI_HPP