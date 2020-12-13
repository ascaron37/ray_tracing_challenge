#ifndef CANVAS_H
#define CANVAS_H
#include <vector>
#include "color.h"

class Canvas {
public:
    Canvas(int width, int height): grid(height, std::vector<Color> (width)) { }
    auto width() const { return grid[0].size(); }
    auto height() const { return grid.size(); }
    Color getColor(int x, int y) const { return grid[y][x]; }
protected:
    std::vector<std::vector<Color>> grid;
};

#endif // CANVAS_H
