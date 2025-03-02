#include "matrix.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows, std::vector<int>(cols)) {}

void Matrix::RandomNumber() {
    std::srand(std::time(nullptr));
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            data[i][j] = std::rand() % 10;
}

void Matrix::print() const {
    for (const auto& row : data) {
        for (int num : row)
            std::cout << std::setw(5) << num;
        std::cout << '\n';
    }
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        std::cout << "Ошибка: Несовместимые размеры матриц для умножения!" << std::endl;
        return Matrix(0, 0);
    }

    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

