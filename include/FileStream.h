/**
 * @file    FileStream.H
 * @author  Henri Keeble
 * @brief   Declarations for an fstream wrapper class.
 */

#ifndef FILESTREAM_H
#define FILESTREAM_H

#include <fstream>
#include <string>
#include <iostream>

namespace IrrGame
{
    class FileStream
    {
        public:
            FileStream();
            FileStream(const std::string& filePath);
            FileStream(const FileStream& param);
            const FileStream& operator=(const FileStream& param);
            virtual ~FileStream();

            std::string ReadLine();
            char ReadChar();

            void WriteLine(const std::string& line);
            void Write(const std::string& data);
            void WriteChar(const char& data);

            void Open();
            void Close();

            bool IsOpen() const;
            bool EndOfFile() const;

            void Seek(std::string data);

        private:
            std::fstream file;
            std::string filePath;

            // Internal copying function
            void cpy(const FileStream& param);
    };
}
#endif // FILESTREAM_H
