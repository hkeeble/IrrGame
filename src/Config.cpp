/**
 * @file    Config.cpp
 * @author  Henri Keeble
 * @brief   Configuration class, holds information about general game configurations. Reads and writes these parameters.
 */
#include "Config.h"

namespace IrrGame
{
    Config::Config() : cfgFName("config")
    {
        // Initialize the stream
        stream = FileStream("data/" + cfgFName + ".cfg");

        this->windowBounds = Rectangle(0,0,std::stoi(ReadParam(WIDTH)),std::stoi(ReadParam(HEIGHT)));
        this->windowCaption = L"IrrGame";
    }

    Config::~Config()
    {
        if(stream.IsOpen())
            stream.Close();
    }

    const Rectangle& Config::WindowBounds() const
    {
        return windowBounds;
    }

    const std::wstring& Config::WindowCaption() const
    {
        return windowCaption;
    }

    void Config::SetWindowBounds(int width, int height)
    {
        windowBounds.width = width;
        windowBounds.height = height;
    }

    void Config::SetWindowCaption(const std::wstring& caption)
    {
        windowCaption = caption;
    }

    std::string Config::ReadParam(const std::string& param)
    {
        // Open a new stream for the file
        stream.Open();
        
        std::string line = "";
        std::string value = "";

        while(!stream.EndOfFile())
        {
            line = stream.ReadLine();
            if(line.find(param.c_str()) != std::string::npos)
            {
                std::vector<std::string> commands = splitStr(line, ':');
                if(commands.size() == 1 || commands.size() == 0)
                    break;
                else if(commands[0] == param)
                    value = commands.back();
            }
        }

        // Close the stream
        stream.Close();

        if(value == "")
            Log("Error reading parameter " + param + " from config file!");
        return value;
    }

    void Config::WriteParam(const std::string& param)
    {

    }

    void Config::WriteParam(const int& param)
    {
        WriteParam(std::to_string(param));
    }
}
