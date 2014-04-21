/**
 * @file    Config.h
 * @author  Henri Keeble
 * @brief   Declarations for a configuration structure, reads and writes configuration data.
 * @see		Config
 */
#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <string>

#include "Shapes.h"
#include "IO.h"

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
            const std::wstring& WindowCaption() const;

            void SetWindowBounds(u32 width, u32 height);
            void SetWindowCaption(const std::wstring& caption);

        private:
            Rectangle windowBounds;
            std::wstring windowCaption;
            const std::string cfgFName;
            FileStream stream;

            std::string ReadParam(const std::string& param);
            void WriteParam(const std::string& param);
            void WriteParam(const u32& param);

            // Paramaters
			const std::string CAPTION	= "caption";
            const std::string WIDTH		= "width";
            const std::string HEIGHT	= "height";
    };
}
#endif // _CONFIG_H_
