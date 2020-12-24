#include <iostream>
#include <fstream>
#include "chapter_2.h"
#include "canvas.h"

using namespace chapter_2;

Projectile tick(const Environment& env, const Projectile& proj) {
    Point position{proj.position + proj.velocity};
    Vector velocity{proj.velocity + env.gravity + env.wind};
    return Projectile{position, velocity};
}

void chapter_2::execute() {
    Canvas c(900, 550);
    Projectile proj{Point(0.0, 1.0, 0.0), Vector(1.0, 1.8, 0.0).normalize() * 11.25};
    Environment env{Vector(0.0, -0.1, 0.0), Vector(-0.01, 0.0, 0.0)};
    for (int i=1;;i++) {
        proj = tick(env, proj);
        c.writePixel(static_cast<int>(proj.position.X()), c.height() - static_cast<int>(proj.position.Y()), Color(1, 0, 0));
        std::cout << "Tick#" << i << " Position: " << proj.position.X() << " " << proj.position.Y() << " " << proj.position.Z() << "\n";
        if (proj.position.Y() <= 0.0) break;
    }
    std::ofstream out("out.ppm");
    if (!out.good()) {
        std::cerr << "Could not open file\n";
        std::exit(1);
    }
    out << c.toPPM();
    out.close();
}
