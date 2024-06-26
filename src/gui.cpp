/*
Date: 21/06/2024

Description: This file implements functions which provide the GUI for the application.

Notes: x
*/

#include <fstream>
#include <iostream>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>
#include "../include/displayer.hpp"
#include "../include/element.hpp"
#include "../include/exception.hpp"
#include "../include/formatter.hpp"
#include "../include/globals.hpp"
#include "../include/gui.hpp"
#include "../include/scene.hpp"
#include "../include/tool.hpp"

namespace Chess
{
        namespace GUI
        {
                /*
                Initialize the GUI.
                */
                void initGUI()
                {
                        // Get the terminal dimensions
                        getDimensions();

                        // Merge header
                        auto header = Tool::mergeGraphics(
                                Tool::readGraphicsFile(
                                        Globals::Constants::HEADER_LEFT_PATH),
                                Tool::readGraphicsFile(
                                        Globals::Constants::HEADER_RIGHT_PATH),
                                Globals::GUI_WIDTH, " ");

                        // Write the header to a file
                        Tool::writeGraphicsFile(Globals::Constants::HEADER_PATH,
                                header);

                        // Merge footer
                        auto footer = Tool::mergeGraphics(
                                Tool::readGraphicsFile(
                                        Globals::Constants::FOOTER_LEFT_PATH),
                                Tool::readGraphicsFile(
                                        Globals::Constants::FOOTER_RIGHT_PATH),
                                Globals::GUI_WIDTH, " ");

                        // Write the footer to a file
                        Tool::writeGraphicsFile(Globals::Constants::FOOTER_PATH,
                                footer);

                        // Clear the screen
                        clearScreen();

                        // Log GUI initialization
                        LOG_INFO("GUI initialized.");
                }

                /*
                Display the intro. Actually, it also prepares the terminal for the
                application by getting the terminal dimensions and clearing the
                screen.
                */
                void displayIntro()
                {
                        // Clear the screen
                        clearScreen();

                        // Create the intro scene
                        Scene introScene = Scene("Intro");

                        // Add the elements to the intro scene
                        introScene.addElement(Element("Header",
                                Globals::Constants::HEADER_PATH,
                                false, false));
                        introScene.addElement(Element("Welcome",
                                Globals::Constants::WELCOME_BANNER_PATH,
                                false, false));
                        introScene.addElement(Element("Footer",
                                Globals::Constants::FOOTER_PATH,
                                false, false));

                        // Format the intro scene
                        formatScene(introScene);

                        // Display the intro scene
                        display(introScene);

                        // Wait for a few seconds
                        Tool::wait(2);

                        LOG_INFO("Intro displayed.");
                }

                /*
                Display the main menu.
                */
                void displayMainMenu()
                {
                        // Clear the screen
                        clearScreen();

                        // Create the main menu scene
                        Scene mainMenuScene = Scene("Main Menu");

                        // Add the elements to the main menu scene
                        mainMenuScene.addElement(Element("Header",
                                Globals::Constants::HEADER_PATH,
                                false, false));
                        mainMenuScene.addElement(Element("Main Menu Banner",
                                Globals::Constants::MAIN_MENU_BANNER_PATH,
                                false, false));
                        mainMenuScene.addElement(Element("Main Menu",
                                Globals::Constants::MAIN_MENU_PATH,
                                true, true));
                        mainMenuScene.addElement(Element("Footer",
                                Globals::Constants::FOOTER_PATH,
                                false, true));

                        // Format the main menu scene
                        formatScene(mainMenuScene);

                        // Display the main menu scene
                        display(mainMenuScene);
                }

                /*
                Display the help menu.
                */
                void displayHelpMenu()
                {
                        // Clear the screen
                        clearScreen();

                        // Create the help menu scene
                        Scene helpMenuScene = Scene("Help Menu");

                        // Add the elements to the help menu scene
                        helpMenuScene.addElement(Element("Header",
                                Globals::Constants::HEADER_PATH,
                                false, false));
                        helpMenuScene.addElement(Element("Help Menu Banner",
                                Globals::Constants::HELP_MENU_BANNER_PATH,
                                false, false));
                        helpMenuScene.addElement(Element("Help Menu",
                                Globals::Constants::HELP_MENU_PATH,
                                true, true));
                        helpMenuScene.addElement(Element("Footer",
                                Globals::Constants::FOOTER_PATH,
                                false, false));

                        // Format the help menu scene
                        formatScene(helpMenuScene);

                        // Display the help menu scene
                        display(helpMenuScene);
                }

                /*
                Display the credits.
                */
                void displayCredits()
                {
                        // Clear the screen
                        clearScreen();

                        // Create the credits scene
                        Scene creditsScene = Scene("Credits");

                        // Add the elements to the credits scene
                        creditsScene.addElement(Element("Header",
                                Globals::Constants::HEADER_PATH,
                                false, false));
                        creditsScene.addElement(Element("Credits Banner",
                                Globals::Constants::CREDITS_BANNER,
                                false, false));
                        creditsScene.addElement(Element("Credits",
                                Globals::Constants::CREDITS_PATH,
                                true, true));
                        creditsScene.addElement(Element("Footer",
                                Globals::Constants::FOOTER_PATH,
                                false, false));

                        // Format the credits scene
                        formatScene(creditsScene);

                        // Display the credits scene
                        display(creditsScene);
                }

                /*
                Display the ending.
                */
                void displayEnding()
                {
                        // Clear the screen
                        clearScreen();

                        // Create the ending scene
                        Scene endingScene = Scene("Ending");

                        // Add the elements to the ending scene
                        endingScene.addElement(Element("Header",
                                Globals::Constants::HEADER_PATH,
                                false, false));
                        endingScene.addElement(Element("Farewell",
                                Globals::Constants::FAREWELL_PATH,
                                false, false));
                        endingScene.addElement(Element("Footer",
                                Globals::Constants::FOOTER_PATH,
                                false, false));

                        // Format the ending scene
                        formatScene(endingScene);

                        // Display the ending scene
                        display(endingScene);

                        // Wait for a few seconds
                        Tool::wait(2);

                        // Clear the screen
                        clearScreen();
                }

                /*
                Display an error.

                @param errorMessage: The error message to be displayed.
                */
                void displayError(const std::vector<std::string>& errorMessage)
                {
                        // Clear the screen
                        clearScreen();

                        // Create the error scene
                        Scene errorScene = Scene("Error");

                        // Add the elements to the error scene
                        errorScene.addElement(Element("Header",
                                Globals::Constants::HEADER_PATH,
                                false, false));
                        errorScene.addElement(Element("Error Banner",
                                Globals::Constants::ERROR_BANNER_PATH,
                                false, false));
                        errorScene.addElement(Element("Error Message",
                                errorMessage, true, false));
                        errorScene.addElement(Element("Footer",
                                Globals::Constants::FOOTER_PATH,
                                false, false));

                        // Format the error scene
                        formatScene(errorScene);

                        // Display the error scene
                        display(errorScene);

                        // Wait for a few seconds
                        Tool::wait(5);
                }

                /*
                Display a simple error.

                @param errorMessage: The error message to be displayed.
                */
                void displaySimpleError(const std::string& errorMessage)
                {
                        // Clear the screen
                        clearScreen();

                        // Display error message
                        displayString(errorMessage, '\n');

                        // Wait for a few seconds
                        Tool::wait(5);
                }

                /*
                Get the dimensions of the terminal and set them in the globals.
                */
                void getDimensions()
                {
                        // Get the terminal dimensions
                        struct winsize w;
                        // Use STDOUT_FILENO for standard output or 0 for standard input
                        if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0)
                        {
                                setDimensions(w.ws_col, w.ws_row);

                                // Log terminal dimensions
                                LOG_INFO("Terminal dimensions: {}x{}", w.ws_col, w.ws_row);
                        }
                        else
                        {
                                // Default terminal dimensions
                                size_t width = 64;
                                size_t height = 32;

                                // Failed to get terminal dimensions, use default values
                                setDimensions(width, height);

                                // Log warning
                                LOG_WARN("Failed to get terminal dimensions, using default values: {}x{}", width, height);
                        }
                }

                /*
                Set the dimensions of the terminal.

                @param width: The width of the terminal.
                @param height: The height of the terminal.
                */
                void setDimensions(const size_t& width, const size_t& height)
                {
                        // Set the terminal dimensions
                        Chess::Globals::GUI_WIDTH = width;
                        Chess::Globals::GUI_HEIGHT = height;
                }

                /*
                Clear the screen.
                */
                void clearScreen()
                {
                        // Clear the screen
                        std::cout << "\033[2J\033[1;1H";
                }
        }
}