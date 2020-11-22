#include <cmath>
#include "tuple.h"

inline bool equal(double a, double b) {
    return fabs(a - b) < 0.000001;
}

bool Tuple::operator==(const Tuple& a) const {
    bool eq = true;
    for (int i=0; i < storage.size(); i++) {
        eq = eq && equal(storage[i], a.storage[i]);
    }
    return eq;
}

Tuple Tuple::operator+(const Tuple& a) const {
    Tuple t;
    t[0] = storage[0] + a[0];
    t[1] = storage[1] + a[1];
    t[2] = storage[2] + a[2];
    t[3] = storage[3] + a[3];
    return t;
}

Tuple Tuple::operator-(const Tuple& a) const {
    Tuple t;
    t[0] = storage[0] - a[0];
    t[1] = storage[1] - a[1];
    t[2] = storage[2] - a[2];
    t[3] = storage[3] - a[3];
    return t;
}

Tuple Tuple::operator-() const {
    Tuple t;
    t[0] = -storage[0];
    t[1] = -storage[1];
    t[2] = -storage[2];
    t[3] = -storage[3];
    return t;
}

Tuple Tuple::operator*(const double a) const {
    Tuple t;
    t[0] = storage[0] * a;
    t[1] = storage[1] * a;
    t[2] = storage[2] * a;
    t[3] = storage[3] * a;
    return t;
}

Tuple Tuple::operator*(const Tuple& a) const {
    Tuple t;
    t[0] = storage[0] * a[0];
    t[1] = storage[1] * a[1];
    t[2] = storage[2] * a[2];
    t[3] = storage[3] * a[3];
    return t;
}

Tuple Tuple::operator/(const double a) const {
    Tuple t;
    if (a != 0.0) {
        t[0] = storage[0] / a;
        t[1] = storage[1] / a;
        t[2] = storage[2] / a;
        t[3] = storage[3] / a;
    }
    return t;
}

double Vector::magnitude() const {
    return sqrt(pow(X(), 2.0) + pow(Y(), 2.0) + pow(Z(), 2.0));
}

Vector Vector::normalize() const {
    Vector v;
    if (magnitude() != 0.0) {
        v = *this / magnitude();
    }
    return v;
}

double Vector::dot(const Vector& a) const {
    double d = X()*a.X() + Y()*a.Y() + Z()*a.Z();
    return d;
}

Vector Vector::cross(const Vector& a) const {
    return Vector(Y()*a.Z() - Z()*a.Y(), Z()*a.X() - X()*a.Z(), X()*a.Y() - Y()*a.X());
}
