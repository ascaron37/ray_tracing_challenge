#include <cmath>
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

Tuple Tuple::operator*(const double a) const {
    Tuple t;
    t.x = this->x * a;
    t.y = this->y * a;
    t.z = this->z * a;
    t.w = this->w * a;
    return t;
}

Tuple Tuple::operator/(const double a) const {
    Tuple t;
    if (a != 0.0) {
        t.x = this->x / a;
        t.y = this->y / a;
        t.z = this->z / a;
        t.w = this->w / a;
    }
    return t;
}

bool Tuple::isPoint() const {
    return equal(w, 1.0);
}

bool Tuple::isVector() const {
    return equal(w, 0.0);
}

double Vector::magnitude() const {
    return sqrt(pow(x, 2.0) + pow(y, 2.0) + pow(z, 2.0));
}

Vector Vector::normalize() const {
    Vector v;
    if (magnitude() != 0.0) {
        v.x = x / magnitude();
        v.y = y / magnitude();
        v.z = z / magnitude();
        v.w = w / magnitude();
    }
    return v;
}

double Vector::dot(const Vector& a) const {
    double d = x*a.x + y*a.y + z*a.z;
    return d;
}

Vector Vector::cross(const Vector& a) const {
    Vector v;
    v.x = y*a.z - z*a.y;
    v.y = z*a.x - x*a.z;
    v.z = x*a.y - y*a.x;
    return v;
}
