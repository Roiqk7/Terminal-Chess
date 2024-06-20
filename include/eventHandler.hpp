/*
Date: 20/06/2024

Description:

Notes: x
*/

#include "globals.hpp"

namespace Chess
{
        namespace EventHandler
        {
                struct Event
                {
                        enum class Type
                        {
                                GameStart, GameEnd, Move, Capture, Check, Checkmate, Stalemate, Draw, Promotion, Castling, EnPassant
                        };

                        Type type;
                        Globals::Player player;
                };
        }
}