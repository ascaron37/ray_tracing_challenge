#include "gtest/gtest.h"
#include <sstream>
#include "canvas.h"

TEST(canvasTest, creatingCanvas) {
    Canvas c(10, 20);
    ASSERT_EQ(c.width(), 10);
    ASSERT_EQ(c.height(), 20);
    for (int i=0; i < c.height(); i++) {
        for (int j=0; j < c.width(); j++) {
            EXPECT_EQ(c.getColor(j, i), Color(0, 0, 0));
        }
    }
}

TEST(canvasTest, writingPixels) {
    Canvas c(10, 20);
    Color red(1, 0, 0);
    c.writePixel(2, 3, red);
    EXPECT_EQ(c.getColor(2, 3), red);
}

// TODO: add out of boundary tests

TEST(canvasTest, constructingPPMHeader) {
    Canvas c(5, 3);
    std::string ppm = c.toPPM();
    std::istringstream stream(ppm);
    std::string line;
    std::getline(stream, line);
    ASSERT_EQ(line, std::string("P3"));
    std::getline(stream, line);
    ASSERT_EQ(line, std::string("5 3"));
    std::getline(stream, line);
    ASSERT_EQ(line, std::string("255"));
}

TEST(canvasTest, contstructingPPMPixelData) {
    Canvas c(5, 3);
    Color c1(1.5, 0, 0);
    Color c2(0, 0.5, 0);
    Color c3(-0.5, 0, 1);

    c.writePixel(0, 0, c1);
    c.writePixel(2, 1, c2);
    c.writePixel(4, 2, c3);

    std::istringstream stream(c.toPPM());
    std::string line;
    // skip header
    std::getline(stream, line);
    std::getline(stream, line);
    std::getline(stream, line);
    // first pixel line
    std::getline(stream, line);
    EXPECT_EQ(line, std::string("255 0 0 0 0 0 0 0 0 0 0 0 0 0 0"));
    std::getline(stream, line);
    EXPECT_EQ(line, std::string("0 0 0 0 0 0 0 128 0 0 0 0 0 0 0"));
    std::getline(stream, line);
    EXPECT_EQ(line, std::string("0 0 0 0 0 0 0 0 0 0 0 0 0 0 255"));
}

TEST(canvasTest, splittingLongLines) {
    Canvas c(10, 2, Color(1, 0.8, 0.6));

    std::istringstream stream(c.toPPM());
    std::string line;
    // skip header
    std::getline(stream, line);
    std::getline(stream, line);
    std::getline(stream, line);
    // first pixel line
    std::getline(stream, line);
    EXPECT_EQ(line, std::string("255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204"));
    std::getline(stream, line);
    EXPECT_EQ(line, std::string("153 255 204 153 255 204 153 255 204 153 255 204 153"));
    std::getline(stream, line);
    EXPECT_EQ(line, std::string("255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204"));
    std::getline(stream, line);
    EXPECT_EQ(line, std::string("153 255 204 153 255 204 153 255 204 153 255 204 153"));
}

TEST(canvasTest, ppmTerminatedByNewline) {
    Canvas c(5, 3);
    std::string ppm{c.toPPM()};
    EXPECT_EQ(ppm.at(ppm.length() - 1), '\n');
}
