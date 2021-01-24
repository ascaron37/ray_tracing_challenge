#include <cmath>

inline bool equal(double a, double b) {
    return std::fabs(a - b) < 0.000001;
}
