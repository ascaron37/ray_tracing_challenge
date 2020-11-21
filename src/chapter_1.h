#ifndef CHAPTER_1_H
#define CHAPTER_1_H
#include "tuple.h"

namespace chapter_1 {
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
#endif // CHAPTER_1_H
