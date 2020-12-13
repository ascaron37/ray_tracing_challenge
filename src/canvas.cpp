#include <cmath>
#include "canvas.h"

std::string Canvas::toPPM() const {
    std::string ppm;
    ppm = createPPMHeader();
    ppm += createPixelMap();

    return ppm;
}

std::string Canvas::createPPMHeader() const {
    std::string ppm;
    ppm += "P3\n";
    ppm += std::to_string(width()) + " " + std::to_string(height()) + "\n";
    ppm += std::to_string(maxPPMColor) + "\n";

    return ppm;
}

std::string Canvas::pixelToString(int x, int y) const {
    Color c{getColor(x, y)};

    return pixelToString(c);
}

std::string Canvas::pixelToString(Color c) const {
    std::string colorStr;
    colorStr = convertColorToPPM(c.red()) + " "
                + convertColorToPPM(c.green()) + " "
                + convertColorToPPM(c.blue());

    return colorStr;
}

std::string Canvas::pixelRowToString(int y) const {
    return pixelRowToString(grid[y]);
}

std::string Canvas::pixelRowToString(const std::vector<Color>& row) const {
    std::string rowString;
    for (auto& pixel: row) {
        rowString += pixelToString(pixel) + " ";
    }
    rowString.at(rowString.length() - 1) = '\n';

    return rowString;
}

std::string Canvas::createPixelMap() const {
    std::string pixelMap;
    for (auto& row: grid) {
        pixelMap += pixelRowToString(row);
    }

    return pixelMap;
}

std::string Canvas::convertColorToPPM(double col) const {
    int ppmColor = std::ceil(col * maxPPMColor);
    if (ppmColor > maxPPMColor)
        ppmColor = maxPPMColor;
    if (ppmColor < 0)
        ppmColor = 0;

    return std::to_string(ppmColor);
}
