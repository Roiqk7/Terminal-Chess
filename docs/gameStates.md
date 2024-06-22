# Game States

## Table of Contents
- [Game States](#game-states)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Definition](#definition)
  - [Game States](#game-states-1)
    - [MainMenu](#mainmenu)
      - [Input Options](#input-options)

## Introduction

Game states are defined in the `include/globals.hpp` header file in the `GameState` enum class. The game states are used to determine the current state of the game which influences the expected user input and game behavior. This documentation aims to provide a brief overview of each game state. The game states are as follows:

- MainMenu
- HelpMenu
- Game
- GameOver

## Definition

```cpp
// include/globals.hpp
enum class GameState
{
        MainMenu, HelpMenu, Game, GameOver
};
```

## Game States

### MainMenu

#### Input Options

- `p` - Play the game
- `h` - View the help menu
- `q` - Quit the game

All other values are considered invalid. User has several opportunities to enter a valid input. If valid input is not entered, main menu will be reprinted and the loop will repeat. This will continue until a valid input is entered and then the event handler will manage the transition to the next game state.

TODO: Add rest of the documentation once relevant.