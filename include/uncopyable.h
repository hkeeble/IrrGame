/**
 * @file    uncopyable.h
 * @author  Henri Keeble
 * @brief   Declaration for an uncopyable base class.
 */

#ifndef _UNCOPYABLE_H_
#define _UNCOPYABLE_H_

namespace IrrGame
{
    class Uncopyable
    {
    public:
        Uncopyable() { }
    private:
        const Uncopyable& operator=(const Uncopyable& param);
        Uncopyable(const Uncopyable& param);
    };
}

#endif // _UNCOPYABLE_H_
