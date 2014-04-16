/**
 * @file    stringext.h
 * @author  Henri Keeble
 * @brief   Extension functions for STL string manipulation.
 */

#ifndef _STRING_EXT_H_
#define _STRING_EXT_H_

#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#include "IO.h"

namespace IrrGame
{
    /**
     * Splits a string given a delimiter.
     * @param str   The string to split.
     * @param delim The delimiter to use to split the string.
     */
    static const std::vector<std::string> splitStr(const std::string str, const char& delim)
    {
        std::stringstream ss(str);
        std::string item;
        std::vector<std::string> elems = std::vector<std::string>();
        while (std::getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }
}

#endif // _STRING_EXT_H_
