#ifndef TUPLE_H
#define TUPLE_H
#include <cmath>
#include <array>
#include <initializer_list>

class Point;
class Vector;

class Tuple {
public:
    Tuple(double a, double b, double c, double d): storage{a, b, c, d} { }
    Tuple(): Tuple(0.0, 0.0, 0.0, 0.0) { }
    bool operator==(const Tuple& a) const;
    Tuple operator+(const Tuple& a) const;
    Tuple operator-(const Tuple& a) const;
    Tuple operator-() const;
    Tuple operator*(const double a) const;
    Tuple operator*(const Tuple& a) const;
    Tuple operator/(const double a) const;
    double& operator[](int i) { return storage[i]; }
    double operator[](int i) const { return storage[i]; }
protected:
    std::array<double, 4> storage;
};

class Point: public Tuple {
public:
    Point(double x, double y, double z): Tuple(x, y, z, 1.0) { }
    Point(): Point(0.0, 0.0, 0.0) { }
    Point(const Tuple& t): Tuple{t} { }
    void setX(double x) { storage[0] = x; }
    void setY(double y) { storage[1] = y; }
    void setZ(double z) { storage[2] = z; }
    auto X() const { return storage[0]; }
    auto Y() const { return storage[1]; }
    auto Z() const { return storage[2]; }
};

class Vector: public Tuple {
public:
    Vector(double x, double y, double z): Tuple(x, y, z, 0.0) { }
    Vector(): Vector(0.0, 0.0, 0.0) { }
    Vector(const Tuple& t): Tuple{t} { }
    void setX(double x) { storage[0] = x; }
    void setY(double y) { storage[1] = y; }
    void setZ(double z) { storage[2] = z; }
    auto X() const { return storage[0]; }
    auto Y() const { return storage[1]; }
    auto Z() const { return storage[2]; }
    double magnitude() const;
    Vector normalize() const;
    double dot(const Vector& a) const;
    Vector cross(const Vector& a) const;
};
#endif // TUPLE_H
