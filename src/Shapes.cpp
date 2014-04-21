/**
 * @file    Shapes.cpp
 * @author  Henri Keeble
 * @brief   Definitions for shape functions.
 */

#include "Shapes.h"

namespace IrrGame
{
    Rectangle::Rectangle(u32 x, u32 y, u32 width, u32 height)
    {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }

    u32 Rectangle::Area() const
    {
        return width*height;
    }

    Cube::Cube(u32 x, u32 y, u32 z, u32 width, u32 height, u32 depth)
    {
        this->x = x;
        this->y = y;
        this->z = z;

        this->width = width;
        this->height = height;
        this->depth = depth;
    }

    u32 Cube::Area() const
    {
        return width*height*depth;
    }
}
