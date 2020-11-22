#include "gtest/gtest.h"
#include "color.h"

TEST(colorTest, colorInit) {
    Color c(-0.5, 0.4, 1.7);
    EXPECT_DOUBLE_EQ(c.red(), -0.5);
    EXPECT_DOUBLE_EQ(c.green(), 0.4);
    EXPECT_DOUBLE_EQ(c.blue(), 1.7);
}

TEST(colorTest, addingColors) {
    Color c1(0.9, 0.6, 0.75);
    Color c2(0.7, 0.1, 0.25);
    EXPECT_EQ(c1 + c2, Color(1.6, 0.7, 1.0));
}

TEST(colorTest, subColors) {
    Color c1(0.9, 0.6, 0.75);
    Color c2(0.7, 0.1, 0.25);
    EXPECT_EQ(c1 - c2, Color(0.2, 0.5, 0.5));
}

TEST(colorTest, mulColorScalar) {
    Color c(0.2, 0.3, 0.4);
    EXPECT_EQ(c * 2.0, Color(0.4, 0.6, 0.8));
}

TEST(colorTest, mulColors) {
    Color c1(1.0, 0.2, 0.4);
    Color c2(0.9, 1.0, 0.1);
    EXPECT_EQ(c1 * c2, Color(0.9, 0.2, 0.04));
}
