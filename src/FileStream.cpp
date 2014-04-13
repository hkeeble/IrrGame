/**
 * @file FileStream.cpp
 * @author Henri Keeble
 * @brief fstream wrapper class.
 */

#include "FileStream.h"

namespace IrrGame
{
    FileStream::FileStream()
    {
        filePath = "";
    }

    FileStream::FileStream(const std::string& filePath)
    {
        this->filePath = filePath;
    }

    FileStream::FileStream(const FileStream& param)
    {
        cpy(param);
    }

    const FileStream& FileStream::operator=(const FileStream& param)
    {
        if(this == &param)
            return *this;
        else
        {
            cpy(param);
            return *this;
        }
    }

    void FileStream::cpy(const FileStream& param)
    {
        this->filePath = param.filePath;
    }

    FileStream::~FileStream()
    {
        if(file.is_open())
            file.close();
    }

    std::string FileStream::ReadLine()
    {
        if(file.is_open())
        {
            std::string retVal;
            getline(file, retVal);
            return retVal;
        }
    }

    char FileStream::ReadChar()
    {
        if(file.is_open())
        {
            char character;
            file.get(character);
            return character;
        }
    }

    void FileStream::WriteLine(const std::string& line)
    {
        file.write((line + "\n").c_str(), line.length() + 1);
    }

    void FileStream::Write(const std::string& data)
    {
        file.write(data.c_str(), data.length());
    }

    void FileStream::WriteChar(const char& data)
    {
        file.write(&data, 1);
    }

    void FileStream::Open()
    {
        Close();
        file.open(filePath, std::ios::in | std::ios::out);
    }

    void FileStream::Close()
    {
        if(file.is_open())
            file.close();
    }

    bool FileStream::IsOpen() const
    {
        return file.is_open();
    }

    bool FileStream::EndOfFile() const
    {
        return file.eof();
    }

    void FileStream::Seek(std::string data)
    {

    }
}
