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

                /*
                Read a graphics file and return it as a vector of strings.

                @param filePath: The path to the graphics file.

                @return: The graphics file as a vector of strings.
                */
                std::vector<std::string> readGraphicsFile(const std::string& filePath)
                {
                        return splitString(readFileContents(filePath), '\n');
                }

                /*
                Write a vector of strings to a file.

                @param filePath: The path to the file to write to.
                @param graphics: The vector of strings to write to the file.
                */
                void writeGraphicsFile(const std::string& filePath,
                        const std::vector<std::string>& graphics)
                {
                        std::string contents;
                        for (const std::string& line : graphics)
                        {
                                contents += line + '\n';
                        }

                        writeFileContents(filePath, contents);
                }

                /*
                Merge two vectors of strings into one vector of strings with the
                specified width and filler to fill the gap between the left and right.

                @param left: The left vector of strings.
                @param right: The right vector of strings.
                @param width: The width of the merged vector.
                @param filler: The filler to fill the gap between the left and right.

                @return: The merged vector of strings.
                */
                std::vector<std::string> mergeGraphics(const std::vector<std::string>& left, const std::vector<std::string>& right,
                        const size_t& width, const std::string& filler)
                {
                        // Merged vector
                        std::vector<std::string> merged;

                        // Get size (width) of the left and right vectors
                        size_t leftSize = left[0].size();
                        size_t rightSize = right[0].size();

                        // Calculate the number of fillers needed
                        size_t fillersNeeded = (width - leftSize - rightSize) / filler.size();

                        // If the width is not enough to fit the left and right, throw an exception
                        if (fillersNeeded < 0)
                        {
                                // Invalid width
                                throw Exception::RunTimeException(
                                        "Negative size provided. Invalid width.");
                        }
                        // If the width is not enough to fit the left and right, throw an exception
                        else if (fillersNeeded < leftSize + rightSize)
                        {
                                // If the width is not enough to fit the left and right, throw an exception
                                throw Exception::InvalidInputException(
                                        "The width is not enough to fit the left and right part of the graphics.");
                        }
                        // If the width is not divisible by the fillers width, throw an exception
                        // Note: Maybe remove and handle more properly without an exception
                        else if (width % filler.size() != 0)
                        {
                                // If the width is not divisible by the fillers width, throw an exception
                                throw Exception::InvalidInputException(
                                        "The width is not divisible by the fillers needed.");
                        }

                        // Create the filler string
                        std::string fillers = std::string(fillersNeeded, filler[0]);

                        // Merge the left and right
                        for (size_t i = 0; i < left.size(); i++)
                        {
                                merged.push_back(left[i] + fillers + right[i]);
                        }

                        return merged;
                }

                /*
                Repeat a pattern a certain number of times.

                @param filePath: The path to the file containing the pattern.
                @param width: The width to fill with the repeated pattern.
                @param delimiter: The delimiter to split the pattern.
                */
                std::vector<std::string> repeatPattern(const std::string& filePath, const size_t& width, const char& delimiter)
                {
                        // Get the pattern
                        std::vector<std::string> pattern = Tool::splitString(
                                Tool::readFileContents(filePath), delimiter);

                        // Repeated pattern
                        std::vector<std::string> repeatedPattern;

                        // Get the number of times to repeat the pattern
                        size_t count = width / pattern[0].size();

                        // Repeat the pattern
                        for (size_t i = 0; i < pattern.size(); i++)
                        {
                                // New line with repeated pattern
                                std::string newLine;

                                // Add the pattern to the new line specified number of times
                                for (int j = count; j > 0; j--)
                                {
                                        newLine += pattern[i];
                                }

                                // Add the new line to the repeated pattern
                                repeatedPattern.push_back(newLine);
                        }

                        return repeatedPattern;
                }
        }
}