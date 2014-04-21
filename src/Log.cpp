/**
 * @file    Log.cpp
 * @author  Henri Keeble
 * @brief   Definitions for writing to a log during debug.
 */

#include "IO.h"

namespace IrrGame
{
    #ifdef _DEBUG
    static std::string logFilePath = "log.txt";
    static FileStream logStream;

	void SetLogFile(const std::string& filePath)
	{
		logFilePath = filePath;
	}

    void Log(const std::string& data)
    {
        logStream = FileStream(logFilePath);
        logStream.Open();

        logStream.WriteLine(data);
        std::cout << "IrrGame Log: " << data << std::endl;

        logStream.Close();
    }
    #endif // _DEBUG

	#ifdef NDEBUG
	void Log(const std::string& data) { }
	#endif // NDEBUG
}
