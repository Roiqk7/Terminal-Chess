/*
Date: 21/06/2024

Description: This file implements utility functions which can be used throughout the application.

Notes: x
*/

#ifndef TOOL_CPP
#define TOOL_CPP

#include <string>
#include <vector>

namespace Chess
{
        namespace Tool
        {
                std::string readFileContents(const std::string& filePath);      // Read the contents of a file
                void writeFileContents(const std::string& filePath,
                        const std::string& contents);                           // Write contents to a file
                void wait(const unsigned int& seconds);                         // Wait for a specified amount of time
                std::vector<std::string> splitString(const std::string& str,
                        const char& delimiter);                                 // Split a string by a delimiter
                std::vector<std::string> readGraphicsFile(const std::string&
                        filePath);                                              // Read a graphics file
                void writeGraphicsFile(const std::string& filePath,
                        const std::vector<std::string>& graphics);               // Write a graphics file
                std::vector<std::string> merge(const std::vector<std::string>&
                        left, const std::vector<std::string>& right,
                        const size_t& width, const std::string& filler);        // Merge two vectors of strings into one vector of strings with the specified width and filler
                std::vector<std::string> repeatPattern(
                        const std::string& filePath, const size_t& width,
                        const char& delimiter);                                 // Repeat a pattern to fill a certain width
        }
}


#endif // !TOOL_CPP