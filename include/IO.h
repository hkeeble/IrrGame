/**
 * @file    FileStream.H
 * @author  Henri Keeble
 * @brief   Declarations for an fstream wrapper class.
 */

#ifndef FILESTREAM_H
#define FILESTREAM_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "stringext.h"

namespace IrrGame
{	
	/** Write data out to the game log and terminal window. */
    extern void Log(const std::string& data);
	
	/** Set the logging file path. */
	extern void SetLogPath(const std::string& filePath);

	/** Represents a file stream. */
    class FileStream
    {
        public:
            FileStream();
            
            /** Construct a new filestream with the given path. Does not open the stream. */
            /**
             *	@param filePath The path of the file with which to use in the stream.
             */
            FileStream(const std::string& filePath);
            FileStream(const FileStream& param);
            const FileStream& operator=(const FileStream& param);
            virtual ~FileStream();

			/** Read the next line from the file. */
            std::string ReadLine();
            
            /** Read the next character from the file. */
            char ReadChar();

			/** Write a line to the file. */
            void WriteLine(const std::string& line);
            
            /** Write a string to the file. */
            void Write(const std::string& data);
            
            /** Write a character to the file. */
            void WriteChar(const char& data);

			/** Open the file stream with the current file path. */
            void Open();
            
            /** Close the file stream. */
            void Close();

			/** Returns whether or not the file is open. */
            bool IsOpen() const;
            
            /** Returns whether or not the stream buffer is at the end of the file. */
            bool EndOfFile() const;

			/** Seek to the given data in the file. */
            void Seek(std::string data);

			/** Get the path of the file stream. */
			const std::string& GetPath() const;
	
        private:
            std::fstream file; /*!< The file stream itself. */
            std::string filePath; /*!< Path of the file being streamed. */

            // Internal copying function
            void cpy(const FileStream& param);
    };
}
#endif // FILESTREAM_H
