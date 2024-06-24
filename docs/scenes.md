# Scenes

## Table of Contents
- [Scenes](#scenes)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Basic key bindings](#basic-key-bindings)
    - [`h`](#h)
    - [`q`](#q)
    - [`x`](#x)
  - [Scenes](#scenes-1)
    - [MainMenu](#mainmenu)
      - [Input Options](#input-options)
      - [Description](#description)
    - [HelpMenu](#helpmenu)
      - [Input Options](#input-options-1)
      - [Description](#description-1)
    - [Credits](#credits)
      - [Input Options](#input-options-2)
      - [Description](#description-2)
    - [GameModeMenu](#gamemodemenu)
      - [Input Options](#input-options-3)
      - [Description](#description-3)
    - [DifficultyMenu](#difficultymenu)
      - [Input Options](#input-options-4)
      - [Description](#description-4)
    - [GamePlay](#gameplay)
      - [Input Options](#input-options-5)
    - [PauseMenu](#pausemenu)
      - [Input Options](#input-options-6)
    - [SaveGame](#savegame)
      - [Input Options](#input-options-7)
    - [LoadGame](#loadgame)
      - [Input Options](#input-options-8)
    - [GameOver](#gameover)
      - [Input Options](#input-options-9)

## Introduction

Scenes create the application as a whole. Each scene has its own set of inputs and expected user interactions. The layout of the various scenes can be found in src/gui.cpp where each scene is implemented. Since this is a terminal and not a traditional GUI application, each scene is not rendered but displayed. And there do not need to be re-displayed 60 times a second. Instead they are only upon user interaction which can change the scene or an element within the scene. Bellow are all the scenes with their respective inputs and brief descriptions.

- MainMenu
- HelpMenu
- Credits
- GameModeMenu
- DifficultyMenu
- GamePlay
- PauseMenu
- SaveGame
- LoadGame
- GameOver
-
## Basic key bindings

### `h`

`h` is usually used as the help key to display the help menu. Every scene has this key binding but not every scene has a custom help menu. So you may be redirected to the main help menu.

### `q`

`q` is usually used as `esc` key. It serves as universal key to go back to where you were or to exit a menu. Every scene has this key binding.

### `x`

`x` is used to exit the application. This is a global key binding. It will exit the application no matter what scene the user is in and will skip the ending scene. Good for quick exits when the boss is coming...

## Scenes

### MainMenu

#### Input Options

- `p` - Play the game
- `h` - View the help menu
- `c` - View the credits
- `q` - Quit the game

#### Description

Main menu is the center hub of the application. From here the user can navigate to the various other scenes. Main menu is automatically displayed on the start of the application.

### HelpMenu

#### Input Options

- `q` - Return to the main menu
-
#### Description

Help menus are displayed when the user presses `h` in any scene. The help will provide the user with basic information on how to navigate the scene and what the scene is about. There are multiple help menus depending on the scene you are in to ensure that the help menu is always relevant... and well... helpful.

### Credits

#### Input Options

- `q` - Return to the main menu

#### Description

The credits show all the special thanks to various projects that were used in the creation of this application. The credits are displayed when the user presses `c` in the main menu.

### GameModeMenu

#### Input Options

- `s` - Single player
- `m` - Multiplayer
- `q` - Return to the main menu

#### Description

In game mode menu the user can pick their opponent. It can either be a computer or another player. The computer opponent is the well known [Stockfish](https://stockfishchess.org). But don't worry, you can pick the difficulty level of the computer... so you don't have to play against the best chess engine in the world if you don't want to.

### DifficultyMenu

#### Input Options

- `h` - Hard
- `m` - Medium
- `e` - Easy
- `q` - Return to the main menu

#### Description

The difficulty menu is summoned when the user picks the computer as their opponent. The user can pick the difficulty level of the computer. There are 3 difficulty levels each carefully chosen. I will not tell you the precise ELO for each difficulty... I will let you speculate.

### GamePlay

#### Input Options

- `chessPieceSquare` - Select a chess piece to move
- `chessSquare` - Select a square to move the chess piece to
- `c` - Cancel the current selection
- `q` - Pause the game

### PauseMenu

#### Input Options

- `r` - Resume the game
- `s` - Save the game
- `l` - Load the game
- `q` - Quit the game and return to the main menu

### SaveGame

#### Input Options

- `1` - Save the game to slot 1
- `2` - Save the game to slot 2
- `3` - Save the game to slot 3
- `q` - Return to the game

### LoadGame

#### Input Options

- `1` - Load the game from slot 1
- `2` - Load the game from slot 2
- `3` - Load the game from slot 3
- `4` - Load the autosave
- `q` - Return to the game

### GameOver

#### Input Options

- `r` - Restart the game
- `q` - Quit the game and return to the main menu
