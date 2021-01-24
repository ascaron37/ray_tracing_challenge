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

bool Matrix::sameDimensions(const Matrix& m) const {
    return m.rows() == rows() && m.columns() == columns();
}
