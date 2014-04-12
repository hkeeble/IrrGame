
#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <string>

#include "Shapes.h"
#include "FileStream.h"
#include "stringext.h"
#include "Log.h"
/**
 * @file    Config.h
 * @author  Henri Keeble
 * @brief   Declarations for a configuration structure, reads and writes configuration data.
 */

namespace IrrGame
{
    /** Represents game configuration data */
    struct Config
    {
        public:
            Config();
            Config(const Rectangle& windowBounds, const std::string& windowCaption);
            ~Config();

            const Rectangle& WindowBounds() const;
            const std::string& WindowCaption() const;

            void SetWindowBounds(int width, int height);
            void SetWindowCaption(const std::string& caption);

            void Refresh();
            void Write() const;

        private:
            Rectangle windowBounds;
            std::string windowCaption;
            const std::string cfgFName;
            FileStream stream;

            const std::string& ReadParam(const std::string& param);
            void WriteParam(const std::string& param);
            void WriteParam(const int& param);

            // Paramaters
            const std::string WIDTH = "width";
            const std::string HEIGHT = "height";
    };
}
#endif // _CONFIG_H_
