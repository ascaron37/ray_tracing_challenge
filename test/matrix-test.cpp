#include "gtest/gtest.h"
#include "matrix.h"

TEST(matrixTest, creatingMatrix4x4) {
    Matrix m{{1.0, 2.0, 3.0, 4.0},
                {5.5, 6.5, 7.5, 8.5},
                {9.0, 10.0, 11.0, 12.0},
                {13.5, 14.5, 15.5, 16.5}};
    EXPECT_DOUBLE_EQ(m[0][0], 1.0);
    EXPECT_DOUBLE_EQ(m[0][3], 4.0);
    EXPECT_DOUBLE_EQ(m[1][0], 5.5);
    EXPECT_DOUBLE_EQ(m[1][2], 7.5);
    EXPECT_DOUBLE_EQ(m[2][2], 11.0);
    EXPECT_DOUBLE_EQ(m[3][0], 13.5);
    EXPECT_DOUBLE_EQ(m[3][2], 15.5);
}

TEST(matrixTest, creatingMatrix2x2) {
    Matrix m(2, 2);
    m[0][0] = -3.0;
    m[0][1] = 5.0;
    m[1][0] = 1.0;
    m[1][1] = -2.0;
    EXPECT_DOUBLE_EQ(m.at(0, 0), -3.0);
    EXPECT_DOUBLE_EQ(m.at(0, 1), 5.0);
    EXPECT_DOUBLE_EQ(m.at(1, 0), 1.0);
    EXPECT_DOUBLE_EQ(m.at(1, 1), -2.0);
}

TEST(matrixTest, creatingMatrix3x3) {
    Matrix m{{-3.0, 5.0, 0.0},
                {1.0, -2.0, -7.0},
                {0.0, 1.0, 1.0}};
    EXPECT_DOUBLE_EQ(m[0][0], -3.0);
    EXPECT_DOUBLE_EQ(m[1][1], -2.0);
    EXPECT_DOUBLE_EQ(m[2][2], 1.0);
}

TEST(matrixTest, equalityTest) {
    Matrix m1{{1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 8, 7, 6},
                {5, 4, 3, 2}};
    Matrix m2{{1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 8, 7, 6},
                {5, 4, 3, 2}};
    EXPECT_TRUE(m1 == m2);
}

TEST(matrixTest, inequalityTest) {
    Matrix m1{{1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 8, 7, 6},
                {5, 4, 3, 2}};
    Matrix m2{{2, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 8, 7, 6},
                {5, 4, 3, 2}};
    EXPECT_TRUE(m1 != m2);
}

TEST(matrixTest, multiplicationMatrix4x4) {
    Matrix m1{{1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 8, 7, 6},
                {5, 4, 3, 2}};
    Matrix m2{{-2, 1, 2, 3},
                {3, 2, 1, -1},
                {4, 3, 6, 5},
                {1, 2, 7, 8}};
    Matrix expect{{20, 22, 50, 48},
                {44, 54, 114, 108},
                {40, 58, 110, 102},
                {16, 26, 46, 42}};
    EXPECT_EQ(m1 * m2, expect);
}

TEST(matrixTest, multiplicationMatrixByTuple) {
    Matrix m{{1, 2, 3, 4},
                {2, 4, 4, 2},
                {8, 6, 4, 1},
                {0, 0, 0, 1}};
    Tuple t(1, 2, 3, 1);
    Tuple expect(18, 24, 33, 1);
    EXPECT_EQ(m * t, expect);
}

TEST(matrixTest, multiplicationByIdentityMatrix) {
    Matrix m{{1, 2, 3, 4},
                {2, 4, 4, 2},
                {8, 6, 4, 1},
                {0, 0, 0, 1}};
    Matrix identity{Matrix::createIdentity(4)};
    EXPECT_EQ(m * identity, m);
}

TEST(matrixTest, multiplicationIdentityMatrixByTuple) {
    Matrix identity{Matrix::createIdentity(4)};
    Tuple t(1, 2, 3, 4);
    EXPECT_EQ(identity * t, t);
}

TEST(matrixTest, transposeMatrix) {
    Matrix m{{0, 9, 3, 0},
                {9, 8, 0, 8},
                {1, 8, 5, 3},
                {0, 0, 5, 8}};
    Matrix trans{{0, 9, 1, 0},
                {9, 8, 8, 0},
                {3, 0, 5, 5},
                {0, 8, 3, 8}};
    EXPECT_EQ(m.transpose(), trans);
}

TEST(matrixTest, transposeIdentityMatrix) {
    Matrix m{Matrix::createIdentity(4)};
    EXPECT_EQ(m.transpose(), m);
}

TEST(matrixTest, determinantMatrix2x2) {
    Matrix m{{1, 5},
            {-3, 2}};
    EXPECT_DOUBLE_EQ(m.determinant(), 17.0);
}

TEST(matrixTest, submatrix3x3to2x2) {
    Matrix m{{1, 5, 0},
            {-3, 2, 7},
            {0, 6, -3}};
    Matrix subm{{-3, 2},
                {0, 6}};
    EXPECT_EQ(m.submatrix(0, 2), subm);
}

TEST(matrixTest, submatrix4x4to3x3) {
    Matrix m{{-6, 1, 1, 6},
            {-8, 5, 8, 6},
            {-1, 0, 8, 2},
            {-7, 1, -1, 1}};
    Matrix subm{{-6, 1, 6},
                {-8, 8, 6},
                {-7, -1, 1}};
    EXPECT_EQ(m.submatrix(2, 1), subm);
}

TEST(matrixTest, minorOfA3x3Matrix) {
    Matrix m{{3, 5, 0},
            {2, -1, -7},
            {6, -1, 5}};
    EXPECT_DOUBLE_EQ(m.submatrix(1, 0).determinant(), 25.0);
    EXPECT_DOUBLE_EQ(m.minor(1, 0), 25.0);
}

TEST(matrixTest, cofactorsOfA3x3Matrix) {
    Matrix m{{3, 5, 0},
            {2, -1, -7},
            {6, -1, 5}};
    EXPECT_DOUBLE_EQ(m.minor(0, 0), -12.0);
    EXPECT_DOUBLE_EQ(m.cofactor(0, 0), -12.0);
    EXPECT_DOUBLE_EQ(m.minor(1, 0), 25.0);
    EXPECT_DOUBLE_EQ(m.cofactor(1, 0), -25.0);
}
