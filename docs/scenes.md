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
    - [Credits](#credits)
      - [Input Options](#input-options-2)
    - [GameModeMenu](#gamemodemenu)
      - [Input Options](#input-options-3)
    - [DifficultyMenu](#difficultymenu)
      - [Input Options](#input-options-4)
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

`h` is usually used as the help key to display the help menu. Not every scene has this key binding but the ones where you would expect to see a help menu do.

### `q`

`q` is usually used as `esc` key to go back to the previous menu or to quit the game. Every scene has this key binding.

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

### Credits

#### Input Options

- `q` - Return to the main menu

### GameModeMenu

#### Input Options

- `s` - Single player
- `m` - Multiplayer
- `q` - Return to the main menu

### DifficultyMenu

#### Input Options

- `h` - Hard
- `m` - Medium
- `e` - Easy
- `q` - Return to the main menu

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
- `q` - Return to the game

### GameOver

#### Input Options

- `r` - Restart the game
- `q` - Quit the game and return to the main menu
