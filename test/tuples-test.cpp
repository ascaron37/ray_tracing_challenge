#include <cmath>
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

TEST(tuplesTest, mulTupleByScalar) {
    Tuple a(1.0, -2.0, 3.0, -4.0);
    ASSERT_EQ(a * 3.5, Tuple(3.5, -7.0, 10.5, -14.0));
}

TEST(tuplesTest, mulTupleByFraction) {
    Tuple a(1.0, -2.0, 3.0, -4.0);
    ASSERT_EQ(a * 0.5, Tuple(0.5, -1.0, 1.5, -2.0));
}

TEST(tuplesTest, divTupleByScalar) {
    Tuple a(1.0, -2.0, 3.0, -4.0);
    ASSERT_EQ(a / 2.0, Tuple(0.5, -1.0, 1.5, -2.0));
}

TEST(tuplesTest, magnitudeVector100) {
    Vector v(1.0, 0.0, 0.0);
    EXPECT_DOUBLE_EQ(v.magnitude(), 1.0);
}

TEST(tuplesTest, magnitudeVector010) {
    Vector v(0.0, 1.0, 0.0);
    EXPECT_DOUBLE_EQ(v.magnitude(), 1.0);
}

TEST(tuplesTest, magnitudeVector001) {
    Vector v(0.0, 0.0, 1.0);
    EXPECT_DOUBLE_EQ(v.magnitude(), 1.0);
}

TEST(tuplesTest, magnitudeVector123) {
    Vector v(1.0, 2.0, 3.0);
    EXPECT_DOUBLE_EQ(v.magnitude(), sqrt(14.0));
}

TEST(tuplesTest, magnitudeVectorNeg123) {
    Vector v(-1.0, -2.0, -3.0);
    EXPECT_DOUBLE_EQ(v.magnitude(), sqrt(14.0));
}

TEST(tuplesTest, normalizingVector400) {
    Vector v(4.0, 0.0, 0.0);
    EXPECT_EQ(v.normalize(), Vector(1.0, 0.0, 0.0));
}

TEST(tuplesTest, normalizingVector123) {
    Vector v(1.0, 2.0, 3.0);
    EXPECT_EQ(v.normalize(), Vector(1.0/sqrt(14.0), 2.0/sqrt(14.0), 3.0/sqrt(14.0)));
}

TEST(tuplesTest, magnitudeNormalizedVector) {
    Vector v(1.0, 2.0, 3.0);
    Vector norm{v.normalize()};
    EXPECT_DOUBLE_EQ(norm.magnitude(), 1.0);
}

TEST(tuplesTest, dotProduct) {
    Vector v1(1.0, 2.0, 3.0);
    Vector v2(2.0, 3.0, 4.0);
    EXPECT_DOUBLE_EQ(v1.dot(v2), 20.0);
}

TEST(tuplesTest, crossProduct) {
    Vector v1(1.0, 2.0, 3.0);
    Vector v2(2.0, 3.0, 4.0);
    EXPECT_EQ(v1.cross(v2), Vector(-1.0, 2.0, -1.0));
    EXPECT_EQ(v2.cross(v1), Vector(1.0, -2.0, 1.0));
}
