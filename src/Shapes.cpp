/**
 * @file    Shapes.cpp
 * @author  Henri Keeble
 * @brief   Definitions for shape functions.
 */

#include "Shapes.h"

namespace IrrGame
{
    Rectangle::Rectangle(int x, int y, int width, int height)
    {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }

    int Rectangle::Area() const
    {
        return width*height;
    }

    Cube::Cube(int x, int y, int z, int width, int height, int depth)
    {
        this->x = x;
        this->y = y;
        this->z = z;

        this->width = width;
        this->height = height;
        this->depth = depth;
    }

    int Cube::Area() const
    {
        return width*height*depth;
    }
}
