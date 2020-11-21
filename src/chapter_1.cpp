#include <iostream>
#include "chapter_1.h"

using namespace chapter_1;

Projectile tick(const Environment& env, const Projectile& proj) {
    Point position{proj.position + proj.velocity};
    Vector velocity{proj.velocity + env.gravity + env.wind};
    return Projectile{position, velocity};
}

void chapter_1::execute() {
    Projectile proj{Point(0.0, 1.0, 0.0), Vector(1.0, 1.0, 0.0).normalize()};
    Environment env{Vector(0.0, -0.1, 0.0), Vector(-0.01, 0.0, 0.0)};
    for (int i=1;;i++) {
        proj = tick(env, proj);
        std::cout << "Tick#" << i << " Position: " << proj.position.getX() << " " << proj.position.getY() << " " << proj.position.getZ() << "\n";
        if (proj.position.getY() <= 0.0) break;
    }
}
