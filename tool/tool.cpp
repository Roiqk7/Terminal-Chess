/*
Date: 21/06/2024

Description: This file defines utility functions which can be used throughout the application.

Notes: x
*/

#include <chrono>
#include <fstream>
#include <sstream>
#include <string>
#include <thread>

namespace Chess
{
        namespace Tool
        {
                /*
                Read the contents of a file and return it as a string.

                @param filePath: The path to the file to read.

                @return: The contents of the file as a string.
                */
                std::string readFileContents(const std::string& filePath)
                {
                        std::ifstream file(filePath);
                        if (!file.is_open())
                        {
                                throw std::runtime_error("Could not open file: " + filePath);
                        }

                        std::stringstream buffer;
                        buffer << file.rdbuf();
                        return buffer.str();
                }

                /*
                Write contents to a file.

                @param filePath: The path to the file to write to.
                @param contents: The contents to write to the file.
                */
                void writeFileContents(const std::string& filePath,
                        const std::string& contents)
                {
                        std::ofstream file(filePath);
                        if (!file.is_open())
                        {
                                throw std::runtime_error("Could not open file: " + filePath);
                        }

                        file << contents;
                }

                /*
                Wait for a specified amount of time.

                @param seconds: The number of seconds to wait.
                */
                void wait(const unsigned int& seconds)
                {
                        std::this_thread::sleep_for(std::chrono::seconds(seconds));
                }
        }
}