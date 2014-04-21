/**
 * @file    Shapes.h
 * @author  Henri Keeble
 * @brief   Declarations for shape structures.
 */

#ifndef _SHAPES_H_
#define _SHAPES_H_

#include <irrlicht.h>

using namespace irr;

namespace IrrGame
{
    struct Rectangle
    {
        Rectangle(u32 x = 0, u32 y = 0, u32 width = 0, u32 height = 0);
        u32 Area() const;

        u32 x, y;
        u32 width, height;
    };

    struct Cube
    {
        Cube(u32 x = 0, u32 y = 0, u32 z = 0, u32 width = 0, u32 height = 0, u32 depth = 0);
        u32 Area() const;

        u32 x, y, z;
        u32 width, height, depth;
    };
}
#endif // _SHAPES_H_
