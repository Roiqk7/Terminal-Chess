# Game States

## Table of Contents
- [Game States](#game-states)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Definition](#definition)
  - [Game States](#game-states-1)
    - [Invalid](#invalid)
    - [MainMenu](#mainmenu)
      - [Input Options](#input-options)
    - [Credits](#credits)
      - [Input Options](#input-options-1)
    - [HelpMenu](#helpmenu)
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

Game states are defined in the `include/globals.hpp` header file in the `GameState` enum class. The game states are used to determine the current state of the game which influences the expected user input and game behavior. This documentation aims to provide a brief overview of each game state. The game states are as follows:

- Invalid
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
        Invalid = 0, MainMenu, Credits, HelpMenu, GameModeMenu,
        DifficultyMenu, GamePlay, PauseMenu, SaveGame,
        LoadGame, GameOver
};
```

## Game States

### Invalid

### MainMenu

#### Input Options

- `p` - Play the game
- `h` - View the help menu
- `q` - Quit the game
- `c` - View the credits

### Credits

#### Input Options

- `q` - Return to the main menu

### HelpMenu

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
- `q` - Quit the game

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
- `q` - Quit the game
