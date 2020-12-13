#include "gtest/gtest.h"
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
