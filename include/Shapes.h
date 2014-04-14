/**
 * @file    Shapes.h
 * @author  Henri Keeble
 * @brief   Declarations for shape structures.
 */

#ifndef _SHAPES_H_
#define _SHAPES_H_

namespace IrrGame
{
    struct Rectangle
    {
        Rectangle(int x = 0, int y = 0, int width = 0, int height = 0);
        int Area() const;

        int x, y;
        int width, height;
    };

    struct Cube
    {
        Cube(int x = 0, int y = 0, int z = 0, int width = 0, int height = 0, int depth = 0);
        int Area() const;

        int x, y, z;
        int width, height, depth;
    };
}
#endif // _SHAPES_H_
