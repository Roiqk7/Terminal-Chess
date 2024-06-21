/*
Date: 20/06/2024

Description: This file defines functions which control the flow of the program.

Notes: x
*/
#ifndef FLOW_CONTROL_HPP
#define FLOW_CONTROL_HPP

namespace Chess
{
        namespace FlowControl
        {
                void mainApplicationLoop();                                     // Makes sure the application proceeds as expected
                void startApplication();                                        // Start the application
                void endApplication();                                          // End the application
        }
}

#endif // !FLOW_CONTROL_HPP