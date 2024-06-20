/*
Date: 20/06/2024

Description: This file defines everything related to the chess board.

Notes: x
*/

#ifndef CHESS_BOARD_HPP
#define CHESS_BOARD_HPP

#include <array>
#include <string>
#include <vector>
#include "../include/chessBoard.hpp"
#include "../include/chessPieces.hpp"
#include "../include/eventHandler.hpp"
#include "../include/globals.hpp"

namespace Chess
{
        namespace Board
        {
                using BoardArray = std::array<Pieces::PieceChar, Globals::Constants::BOARD_ARRAY_SIZE>;

                class Board
                {
                public:
                        EventHandler::EventStack eventStack;
                private:
                };
        }
}

#endif // !CHESS_BOARD_HPP