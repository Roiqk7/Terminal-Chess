/*
Date: 20/06/2024

Description: This file contains functions and datatypes related to event handling.

Notes: x
*/

#include <stack>
#include "globals.hpp"

namespace Chess
{
        namespace EventHandler
        {
                struct Event
                {
                        enum class Type
                        {
                                GameStart, GameEnd, Move, Capture, Check,
                                        Checkmate, Stalemate, Draw, Promotion,
                                        Castling, EnPassant
                        };

                        Type type;
                        Globals::Player player;
                };

                using EventStack = std::stack<Event>;
        }
}