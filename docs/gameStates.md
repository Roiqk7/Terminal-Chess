# Game States

## Table of Contents
- [Game States](#game-states)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Definition](#definition)
  - [Game States](#game-states-1)
    - [MainMenu](#mainmenu)
      - [Input Options](#input-options)
  - [Credits](#credits)
    - [Input Options](#input-options-1)
    - [HelpMenu](#helpmenu)
      - [Input Options](#input-options-2)
    - [GameModeMenu](#gamemodemenu)
    - [DifficultyMenu](#difficultymenu)
  - [GamePlay](#gameplay)
  - [PauseMenu](#pausemenu)
  - [SaveGame](#savegame)
  - [LoadGame](#loadgame)
  - [GameOver](#gameover)

## Introduction

Game states are defined in the `include/globals.hpp` header file in the `GameState` enum class. The game states are used to determine the current state of the game which influences the expected user input and game behavior. This documentation aims to provide a brief overview of each game state. The game states are as follows:

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

## Definition

```cpp
// include/globals.hpp
enum class GameState
{
        MainMenu, Credits, HelpMenu, GameModeMenu,
        DifficultyMenu, GamePlay, PauseMenu, SaveGame,
        LoadGame, GameOver
};
```

## Game States

### MainMenu

#### Input Options

- `p` - Play the game
- `h` - View the help menu
- `q` - Quit the game
- `c` - View the credits

## Credits

### Input Options

- `q` - Return to the main menu

### HelpMenu

#### Input Options

- `q` - Return to the main menu

### GameModeMenu

- `s` - Single player
- `m` - Multiplayer

### DifficultyMenu

- `h` - Hard
- `m` - Medium
- `e` - Easy
- `q` - Return to the main menu

## GamePlay

- `chessPieceSquare` - Select a chess piece to move
- `chessSquare` - Select a square to move the chess piece to
- `c` - Cancel the current selection
- `q` - Pause the game

## PauseMenu

- `r` - Resume the game
- `s` - Save the game
- `l` - Load the game
- `q` - Quit the game

## SaveGame

- `1` - Save the game to slot 1
- `2` - Save the game to slot 2
- `3` - Save the game to slot 3
- `q` - Return to the game

## LoadGame

- `1` - Load the game from slot 1
- `2` - Load the game from slot 2
- `3` - Load the game from slot 3
- `q` - Return to the game

## GameOver

- `r` - Restart the game
- `q` - Quit the game
