#include <iostream>
#include <string>

// ANSI color codes
const std::string RESET_COLOR = "\033[0m";
const std::string WHITE_PIECE_COLOR = "\033[97m"; // Bright white for pieces
const std::string BLACK_PIECE_COLOR = "\033[30m"; // Black for pieces
const std::string WHITE_TILE_COLOR = "\033[48;5;230m"; // Light gray background for white tiles
const std::string BLACK_TILE_COLOR = "\033[48;5;52m"; // Dark red background for black tiles

// Function to print a piece on a tile with colors
void printColoredTile(char piece, bool isPieceWhite, bool isTileWhite) {
    std::string pieceColor = isPieceWhite ? WHITE_PIECE_COLOR : BLACK_PIECE_COLOR;
    std::string tileColor = isTileWhite ? WHITE_TILE_COLOR : BLACK_TILE_COLOR;

    std::cout << tileColor << pieceColor << piece << RESET_COLOR;
}

int main() {
    // Example: Print a white pawn on a black tile
    printColoredTile('P', true, false);
    std::cout << std::endl;

    // Example: Print a black knight on a white tile
    printColoredTile('N', false, true);
    std::cout << std::endl;

    return 0;
}