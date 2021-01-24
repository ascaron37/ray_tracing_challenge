#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <cstddef>
#include <initializer_list>
#include "tuple.h"

class Matrix {
public:
    Matrix(int rows, int columns): mat(rows, std::vector<double> (columns)) { }
    Matrix(std::initializer_list<std::vector<double>> dat): mat(dat) { }
    std::vector<double>& operator[](int i) { return mat[i]; }
    const std::vector<double>& operator[](int i) const { return mat[i]; }
    bool operator==(const Matrix& m) const;
    bool operator!=(const Matrix& m) const;
    Matrix operator*(const Matrix& m) const;
    Tuple operator*(const Tuple& t) const;
    Matrix transpose() const;
    double determinant() const;
    Matrix submatrix(int row, int column) const;
    double minor(int row, int column) const;
    double cofactor(int row, int column) const;
    std::size_t rows() const;
    std::size_t columns() const;
    static Matrix const createIdentity(int const dim) {
        assert(dim > 0);
        Matrix ident(dim, dim);
        for (int i=0; i < dim; i++)
            ident[i][i] = 1.0;
        return ident;
    }
    // TODO: add bound checks
    double at(int row, int column) const { return mat[row][column]; }
private:
    bool sameDimensions(const Matrix& m) const;
    std::vector<std::vector<double>> mat;
};

inline std::size_t Matrix::rows() const {
    return mat.size();
}

inline std::size_t Matrix::columns() const {
    if (rows() > 0)
        return mat[0].size();
    return rows();
}

#endif // MATRIX_H
