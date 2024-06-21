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
        }
}


#endif // !TOOL_CPP