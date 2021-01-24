#include <cmath>
#include <cassert>
#include "matrix.h"
#include "utils.h"

bool Matrix::operator==(const Matrix& m) const {
    if (!sameDimensions(m)) return false;
    for (std::size_t i=0; i < rows(); i++)
        for (std::size_t j=0; j < columns(); j++)
            if (!equal(m[i][j], (*this)[i][j]))
                return false;
    return true;
}

bool Matrix::operator!=(const Matrix& m) const {
    return !operator==(m);
}

// TODO: check how other libraries multiply matrices
Matrix Matrix::operator*(const Matrix& m) const {
    assert(sameDimensions(m));
    Matrix res(rows(), columns());
    for (std::size_t i=0; i < rows(); i++)
        for (std::size_t j=0; j < columns(); j++)
            res[i][j] = mat[i][0] * m[0][j] +
                        mat[i][1] * m[1][j] +
                        mat[i][2] * m[2][j] +
                        mat[i][3] * m[3][j];
    return res;
}

Tuple Matrix::operator*(const Tuple& t) const {
    Tuple res;
    for (std::size_t i=0; i < rows(); i++)
        res[i] = mat[i][0] * t[0] +
                    mat[i][1] * t[1] +
                    mat[i][2] * t[2] +
                    mat[i][3] * t[3];
    return res;
}

// TODO: assert that it is a quadratic matrix
Matrix Matrix::transpose() const {
    Matrix m(rows(), rows());
    for (int i=0; i < rows(); i++)
        for (int j=0; j < rows(); j++)
            m[i][j] = mat[j][i];
    return m;
}

double Matrix::determinant() const {
    if (rows() == 2)
        return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
    return 0.0;
}

Matrix Matrix::submatrix(int row, int column) const {
    assert(row >= 0 && row < rows());
    assert(column >= 0 && column < columns());
    Matrix m(rows()-1, columns()-1);
    for (int i=0; i < m.rows(); i++) {
        for (int j=0; j < m.columns(); j++) {
            int newRow{i < row? i: i+1};
            int newColumn{j < column? j: j+1};
            m[i][j] = mat[newRow][newColumn];
        }
    }
    return m;
}

double Matrix::minor(int row, int column) const {
    return submatrix(row, column).determinant();
}

double Matrix::cofactor(int row, int column) const {
    if (row+column % 2)
        return -minor(row, column);
    return minor(row, column);
}

bool Matrix::sameDimensions(const Matrix& m) const {
    return m.rows() == rows() && m.columns() == columns();
}
