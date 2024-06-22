#!/bin/bash

# Exit immediately if a command exits with a non-zero status.
set -e

# Save the current directory
original_dir=$(pwd)

# Create a build directory if it doesn't exist
if [ ! -d "build" ]; then
        echo "Creating build directory..."
        mkdir build
fi

# Check if the current directory is not already 'build'
if [[ $(basename "$PWD") != "build" ]]; then
        echo "Moving to the build directory..."
        cd build
fi

# Check if the script was called with the 'dev' argument
if [ "$1" == "dev" ]; then
        echo "Configuring the project with CMake in development mode..."
        # Configure the project with CMake in development mode
        cmake .. -DDEVELOPMENT_MODE=ON
else
        echo "Configuring the project with CMake in default mode..."
        # Configure the project with CMake in default mode
        cmake .. -DDEVELOPMENT_MODE=OFF
fi

echo "Building the project..."

# Build the project
make

# Move back to the original directory after building
echo "Moving back to the original directory..."
cd "$original_dir"