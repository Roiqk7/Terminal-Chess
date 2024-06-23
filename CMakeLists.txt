# Specify the minimum version for CMake and the project's name
cmake_minimum_required(VERSION 3.10)
project(TerminalChess VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

# Option to toggle development mode
option(DEVELOPMENT_MODE "Build the project in development mode" OFF)
message(STATUS "Development mode: ${DEVELOPMENT_MODE}")

# Add the executable
add_executable(TerminalChess src/terminalChess.cpp)

# Include directories
target_include_directories(TerminalChess PUBLIC "include/")

# Add source files
target_sources(TerminalChess PRIVATE
        src/chessBoard.cpp
        src/chessPieces.cpp
        src/displayer.cpp
        src/element.cpp
        src/event.cpp
        src/eventHandler.cpp
        src/exception.cpp
        src/application.cpp
        src/formatter.cpp
        src/gameHandler.cpp
        src/globals.cpp
        src/gui.cpp
        src/inputHandler.cpp
        src/scene.cpp
        tool/tool.cpp
        src/validator.cpp
)

# Conditionally include spdlog in development mode
if(DEVELOPMENT_MODE)
        # Assuming spdlog is installed system-wide or is available in a known path
        find_package(spdlog REQUIRED)
        target_link_libraries(TerminalChess PRIVATE spdlog::spdlog)
        # Define DEVELOPMENT preprocessor macro
        target_compile_definitions(TerminalChess PRIVATE DEVELOPMENT=1)
endif()