#ifndef TUPLE_H
#define TUPLE_H
#include <math.h>

class Tuple {
public:
    Tuple(double x, double y, double z, double w): x{x}, y{y}, z{z}, w{w} { }
    Tuple(): Tuple(0.0, 0.0, 0.0, 0.0) {}
    bool operator==(const Tuple& a) const;
    Tuple operator+(const Tuple& a) const;
    Tuple operator-(const Tuple& a) const;
    Tuple operator-() const;
    bool isPoint() const;
    bool isVector() const;
    auto getX() const { return x; } // inline
    auto getY() const { return y; }
    auto getZ() const { return z; }
    auto getW() const { return w; }
private:
    double x;
    double y;
    double z;
    double w;
};

class Point: public Tuple {
public:
    Point(double x, double y, double z);
};

class Vector: public Tuple {
public:
    Vector(double x, double y, double z);
};
#endif // TUPLE_H
