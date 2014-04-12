/**
 * @file    Log.cpp
 * @author  Henri Keeble
 * @brief   Definitions for writing to a log during debug.
 */

#include "Log.h"

namespace IrrGame
{
    #ifdef _DEBUG
    static const std::string logFilePath = "log.txt";
    static FileStream logStream;

    void Log(const std::string& data)
    {
        logStream = FileStream();
        logStream.Open();

        logStream.WriteLine(data);
        std::cout << "IrrGame Log: " << data << std::endl;

        logStream.Close();
    }
    #endif // _DEBUG

    #ifdef NDEBUG
    void Log(const std::string& data) { }
    #endif
}
