#include "tuple.h"

inline bool equal(double a, double b) {
    return fabs(a - b) < 0.000001;
}

bool Tuple::operator==(const Tuple& a) const {
    return equal(this->w, a.w) &&
            equal(this->x, a.x) &&
            equal(this->y, a.y) &&
            equal(this->z, a.z);
}

Tuple Tuple::operator+(const Tuple& a) const {
    Tuple t;
    t.x = this->x + a.x;
    t.y = this->y + a.y;
    t.z = this->z + a.z;
    t.w = this->w + a.w;
    return t;
}

Tuple Tuple::operator-(const Tuple& a) const {
    Tuple t;
    t.x = this->x - a.x;
    t.y = this->y - a.y;
    t.z = this->z - a.z;
    t.w = this->w - a.w;
    return t;
}

Tuple Tuple::operator-() const {
    Tuple t;
    t.x = -this->x;
    t.y = -this->y;
    t.z = -this->z;
    t.w = -this->w;
    return t;
}

bool Tuple::isPoint() const {
    return equal(w, 1.0);
}

bool Tuple::isVector() const {
    return equal(w, 0.0);
}

Point::Point(double x, double y, double z): Tuple{x, y, z, 1.0} {
}

Vector::Vector(double x, double y, double z): Tuple{x, y, z, 0.0} {
}
