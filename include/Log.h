/**
 * @file   Log.h
 * @author Henri Keeble
 * @brief  Debug trace singleton.
*/

#ifndef LOG_H
#define LOG_H

#include <string>

#include "FileStream.h"

namespace IrrGame
{
    extern void Log(const std::string& data);
}

#endif // LOG_H
