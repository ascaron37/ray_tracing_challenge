#ifndef TUPLE_H
#define TUPLE_H
#include <math.h>

class Point;
class Vector; 

class Tuple {
public:
    Tuple(double x, double y, double z, double w): x{x}, y{y}, z{z}, w{w} { }
    Tuple(): Tuple(0.0, 0.0, 0.0, 0.0) { }
    bool operator==(const Tuple& a) const;
    Tuple operator+(const Tuple& a) const;
    Tuple operator-(const Tuple& a) const;
    Tuple operator-() const;
    Tuple operator*(const double a) const;
    Tuple operator/(const double a) const;
    bool isPoint() const;
    bool isVector() const;
    auto getX() const { return x; } // inline
    auto getY() const { return y; }
    auto getZ() const { return z; }
    auto getW() const { return w; }
protected:
    double x;
    double y;
    double z;
    double w;
};

class Point: public Tuple {
public:
    Point(double x, double y, double z): Tuple{x, y, z, 1.0} { }
    Point(): Point(0.0, 0.0, 0.0) { }
    Point(const Tuple& t): Tuple{t} { }
};

class Vector: public Tuple {
public:
    Vector(double x, double y, double z): Tuple{x, y, z, 0.0} { }
    Vector(): Vector(0.0, 0.0, 0.0) { }
    Vector(const Tuple& t): Tuple{t} { }
    double magnitude() const;
    Vector normalize() const;
    double dot(const Vector& a) const;
    Vector cross(const Vector& a) const;
};
#endif // TUPLE_H
