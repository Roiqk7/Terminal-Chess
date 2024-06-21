# Specify the minimum version for CMake and the project's name
cmake_minimum_required(VERSION 3.10)
project(TerminalChess VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add the executable
add_executable(TerminalChess src/terminalChess.cpp)

# Include directories
target_include_directories(TerminalChess PUBLIC "include/")

# Add source files
target_sources(TerminalChess PRIVATE
    src/chessBoard.cpp
    src/chessPieces.cpp
    src/eventHandler.cpp
    src/gameHandler.cpp
    src/gui.cpp
    src/inputHandler.cpp
    tool/tool.cpp
)