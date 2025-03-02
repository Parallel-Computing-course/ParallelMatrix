#include "parallel_mult.h"
#include <omp.h>
#include <iostream>


Matrix parallelMultiply(const Matrix& A, const Matrix& B) {
    if (A.cols != B.rows) {
        std::cout << "Ошибка: Несовместимые размеры матриц для умножения!" << std::endl;
        return Matrix(0, 0);
    }

    Matrix result(A.rows, B.cols);

    #pragma omp parallel for schedule(static)
    for (int i = 0; i < A.rows; ++i) {
        for (int j = 0; j < B.cols; ++j) {
            for (int k = 0; k < A.cols; ++k) {
                result.data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }
    }
    return result;
}

