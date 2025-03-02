#include "matrix.h"
#include "parallel_mult.h"
#include <iostream>
#include <chrono>

int main() {
    int size = 10;
    Matrix A(size, size), B(size, size);

    A.RandomNumber();
    B.RandomNumber();

    std::cout << "Матрица A:\n";
    A.print();
    std::cout << "Матрица B:\n";
    B.print();

    auto start = std::chrono::high_resolution_clock::now();
    Matrix C = A * B;
    std::cout << "\nРезультат обычного умножения:\n";
    C.print();
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Время обычного умножения: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " мкс\n";

    start = std::chrono::high_resolution_clock::now();
    Matrix С = parallelMultiply(A, B);
    std::cout << "\nРезультат параллельного умножения:\n";
    С.print();
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Время параллельного умножения: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " мкс\n";

    return 0;
}
