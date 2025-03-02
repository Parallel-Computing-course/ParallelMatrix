#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix {
public:
    int rows, cols;
    std::vector<std::vector<int>> data;

    Matrix(int rows, int cols);
    void RandomNumber();
    void print() const;
    Matrix operator*(const Matrix& other) const;
};

#endif
