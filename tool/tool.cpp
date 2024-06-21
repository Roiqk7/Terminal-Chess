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
#include <vector>
#include "../include/exception.hpp"
#include "../include/globals.hpp"
#include "../include/tool.hpp"

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
                                LOG_ERROR("Could not open file: {}", filePath);
                                throw Exception::RunTimeException("Could not open file: " + filePath);
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
                                LOG_ERROR("Could not open file: {}", filePath);
                                throw Exception::RunTimeException("Could not open file: " + filePath);
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

                /*
                Split a string by a delimiter.

                @param str: The string to split.
                @param delimiter: The delimiter to split the string by.

                @return: A vector of strings containing the split parts.
                */
                std::vector<std::string> splitString(const std::string& str,
                        const char& delimiter)
                {
                        std::vector<std::string> parts;
                        std::stringstream ss(str);
                        std::string part;

                        while (std::getline(ss, part, delimiter))
                        {
                                parts.push_back(part);
                        }

                        return parts;
                }
        }
}