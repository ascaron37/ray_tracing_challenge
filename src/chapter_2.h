#ifndef CHAPTER_2_H
#define CHAPTER_2_H
#include "tuple.h"

namespace chapter_2 {
struct Projectile {
    Point position;
    Vector velocity;
};

struct Environment {
    Vector gravity;
    Vector wind;
};

void execute();
}
#endif // CHAPTER_2_H
