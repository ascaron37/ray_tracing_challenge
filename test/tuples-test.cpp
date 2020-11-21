#include "gtest/gtest.h"
#include "tuple.h"

// TODO:
// check classes
// check initializations
// check suffix for floating point numbers
// check floating point tests in gtest
TEST(tuplesTest, tupleIsAPoint) {
    Tuple a(4.3, -4.2, 3.1, 1.0);
    EXPECT_DOUBLE_EQ(a.getX(), 4.3);
    EXPECT_DOUBLE_EQ(a.getY(), -4.2);
    EXPECT_DOUBLE_EQ(a.getZ(), 3.1);
    EXPECT_NEAR(a.getW(), 1.0, 0.0001);
    EXPECT_TRUE(a.isPoint());
    ASSERT_FALSE(a.isVector());
}

TEST(tuplesTest, tupleIsAVector) {
    Tuple a(4.3, -4.2, 3.1, 0.0);
    EXPECT_DOUBLE_EQ(a.getX(), 4.3);
    EXPECT_DOUBLE_EQ(a.getY(), -4.2);
    EXPECT_DOUBLE_EQ(a.getZ(), 3.1);
    EXPECT_NEAR(a.getW(), 0.0, 0.0001);
    EXPECT_FALSE(a.isPoint());
    ASSERT_TRUE(a.isVector());
}

TEST(tuplesTest, pointIsATuple) {
    Point p(4.0, -4.0, 3.0);
    Tuple a(4.0, -4.0, 3.0, 1.0);
    ASSERT_TRUE(static_cast<Tuple>(p) == a);
}

TEST(tuplesTest, vectorIsATuple) {
    Vector v(4.0, -4.0, 3.0);
    Tuple a(4.0, -4.0, 3.0, 0.0);
    ASSERT_TRUE(static_cast<Tuple>(v) == a);
}

TEST(tuplesTest, addingTwoTuples) {
    Tuple a1(3.0, -2.0, 5.0, 1.0);
    Tuple a2(-2.0, 3.0, 1.0, 0.0);
    ASSERT_EQ(a1 + a2, Tuple(1.0, 1.0, 6.0, 1.0));
}

TEST(tuplesTest, subtractingTwoPoints) {
    Point p1(3.0, 2.0, 1.0);
    Point p2(5.0, 6.0, 7.0);
    ASSERT_EQ(p1 - p2, Vector(-2.0, -4.0, -6.0));
}

TEST(tuplesTest, subtractingVectorFromPoint) {
    Point p(3.0, 2.0, 1.0);
    Vector v(5.0, 6.0, 7.0);
    ASSERT_EQ(p - v, Point(-2.0, -4.0, -6.0));
}

TEST(tuplesTest, subtractingTwoVectors) {
    Vector v1(3.0, 2.0, 1.0);
    Vector v2(5.0, 6.0, 7.0);
    ASSERT_EQ(v1 - v2, Vector(-2.0, -4.0, -6.0));
}

TEST(tuplesTest, negatingTuple) {
    Tuple a(1.0, -2.0, 3.0, -4.0);
    ASSERT_EQ(-a, Tuple(-1.0, 2.0, -3.0, 4.0));
}
