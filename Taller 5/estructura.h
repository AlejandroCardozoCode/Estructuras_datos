#ifndef __ESTRUCTURA_H__
#define __ESTRUCTURA_H__

#include <cmath>

struct Point
{
    float X, Y, Z;
    float distanceTo(const Point &b) const
    {
        float x = X - b.X;
        float y = Y - b.Y;
        float z = Z - b.Z;
        return (std::sqrt((x * x) + (y * y) + (z * z)));
    }
};

#endif // __ESTRUCTURA_H__