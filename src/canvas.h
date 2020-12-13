#ifndef CANVAS_H
#define CANVAS_H
#include <vector>
#include <sstream>
#include "color.h"

class Canvas {
public:
    Canvas(int width, int height, Color col): grid(height, std::vector<Color> (width, col)) { }
    Canvas(int width, int height): grid(height, std::vector<Color> (width)) { }
    auto width() const { return grid[0].size(); }
    auto height() const { return grid.size(); }
    Color getColor(int x, int y) const { return grid[y][x]; }
    void writePixel(int x, int y, Color col) { grid[y][x] = col; }
    std::string toPPM() const;
private:
    std::string createPPMHeader() const;
    std::string pixelToString(int x, int y) const;
    std::string pixelToString(Color c) const;
    std::string pixelRowToString(int y) const;
    std::string pixelRowToString(const std::vector<Color>& row) const;
    std::string createPixelMap() const;
    std::string convertColorToPPM(double color) const;
    std::string postprocessLineLength(std::string line) const;
protected:
    int maxPPMColor{255};
    int maxLineLength{70};
    std::vector<std::vector<Color>> grid;
};


#endif // CANVAS_H
