#ifndef COLOR_H
#define COLOR_H
#include "tuple.h"

class Color: public Tuple {
public:
    Color(double red, double green, double blue): Tuple(red, green, blue, 0.0) { }
    Color(): Color(0.0, 0.0, 0.0) { }
    Color(const Tuple& t): Tuple{t} { }
    void setRed(double red) { storage[0] = red; }
    void setGreen(double green) { storage[1] = green; }
    void setBlue(double blue) { storage[2] = blue; }
    auto red() const { return storage[0]; }
    auto green() const { return storage[1]; }
    auto blue() const { return storage[2]; }
};
#endif // COLOR_H
