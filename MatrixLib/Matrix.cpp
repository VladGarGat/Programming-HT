#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

double** createMatrix(size_t rows, size_t cols)
{
    double** matrix = new double* [rows];
    for (size_t idx = 0; idx < rows; ++idx)
        matrix[idx] = new double[cols];
    return matrix;
}
void deleteMatrix(double** matrix, size_t rows, size_t cols)
{
    for (size_t idx = 0; idx < rows; ++idx)
        delete[] matrix[idx];
    delete[] matrix;
}
void inputMatrix(double** matrix, size_t rows, size_t cols)
{
    std::cout << "Input matrix with " << cols << " cols:\n";
    for (size_t r = 0; r < rows; ++r)
    {
        std::cout << "Input " << r << " row: ";
        for (size_t c = 0; c < cols; ++c)
            std::cin >> matrix[r][c];
    }
}
double** inputFileMatrix(char const* filename, size_t& rows, size_t& cols)
{
    std::ifstream in(filename);
    if (!in.is_open())
        throw std::runtime_error("Failed to open matrix file");
    in >> rows >> cols;
    double** matrix = createMatrix(rows, cols);
    for (size_t r = 0; r < rows; ++r)
        for (size_t c = 0; c < cols; ++c)
            in >> matrix[r][c]; //*(*(matrix+r)+c)
    in.close();
    return matrix;
}
void printMatrix(double** matrix, size_t rows, size_t cols)
{
    for (size_t r = 0; r < rows; ++r)
    {
        for (size_t c = 0; c < cols; ++c)
            std::cout << matrix[r][c] << '\t';
        std::cout << '\n';
    }
    std::cout << '\n';
}
void zeros(double** matrix, size_t rows, size_t cols)
{
    fill(matrix, rows, cols, 0);
}
void ones(double** matrix, size_t rows, size_t cols)
{
    fill(matrix, rows, cols, 1);
}
void fill(double** matrix, size_t rows, size_t cols, double val)
{
    for (size_t r = 0; r < rows; ++r)
        for (size_t c = 0; c < cols; ++c)
            matrix[r][c] = val;
}
double** linspace(size_t length)
{
    double** vec = createMatrix(1, length);
    for (size_t idx = 0; idx < length; ++idx)
        vec[0][idx] = idx + 1;
    return vec;
}
double** transpose(double** matrix, size_t rows, size_t cols)
{
    double** transposed = createMatrix(cols, rows);
    for (size_t r = 0; r < rows; ++r)
        for (size_t c = 0; c < cols; ++c)
            transposed[c][r] = matrix[r][c];
    return transposed;
}
template <typename Type>
void Swap(Type& a, Type& b)
{
    Type tmp = a;
    a = b;
    b = tmp;
}
void rotate180(double** matrix, size_t rows, size_t cols)
{
    for (size_t r = 0; r < rows; ++r)
        for (size_t c = 0; c < cols / 2; ++c)
            Swap(matrix[r][c], matrix[r][cols - c - 1]);

    for (size_t r = 0; r < rows / 2; ++r)
        Swap(matrix[r], matrix[rows - r - 1]);
}
double& findMinimum(double** matrix, size_t rows, size_t cols)
{
    double minimum = **matrix;
    size_t r_min = 0;
    size_t c_min = 0;
    for (size_t r = 0; r < rows; ++r)
        for (size_t c = 0; c < cols; ++c)
            if (matrix[r][c] < minimum)
            {
                minimum = matrix[r][c];
                r_min = r;
                c_min = c;
            }
    return matrix[r_min][c_min];
}
double& minmaxMatrix(double** matrix, size_t rows, size_t cols)
{
    size_t r_min = 0;
    size_t c_min = 0;
    size_t r_max = 0;
    size_t c_max = 0;
    double minimum;
    double maximum;
    for (size_t r = 0; r < rows; ++r) {
        minimum = matrix[r][0];
        r_min = r;
        c_min = 0;
        for (size_t c = 1; c < cols; ++c)
            if (matrix[r][c] < minimum) {
                minimum = matrix[r][c];
                r_min = r;
                c_min = c;
            }
        if (r == 0 || minimum > maximum) {
            maximum = minimum;
            r_max = r_min;
            c_max = c_min;
        }
    }
    return matrix[r_max][c_max];
}
void mixMatrix(double** matrix, size_t rows, size_t cols, size_t k1, size_t k2)
{
    if (k1 == k2) return;
    if (k1 >= rows || k1 >= cols || k2 >= rows || k2 >= cols)
        return;
    Swap(matrix[k1], matrix[k2]);
    for (size_t r = 0; r < rows; ++r)
        Swap(matrix[r][k1], matrix[r][k2]);
}
void randMatrix(double** matrix, size_t rows, size_t cols, double minval, double maxval)
{
    for (size_t r = 0; r < rows; ++r)
        for (size_t c = 0; c < cols; ++c)
            matrix[r][c] = ((maxval - minval) * rand()) / RAND_MAX + minval;
}


double** multMatrix(double lambda, double** M, size_t rows, size_t cols)
{
    for (size_t r = 0; r < rows; ++r)
        for (size_t c = 0; c < cols; ++c)
        {
            M[r][c] *= lambda;
        }
    return M;
}
double** plusMatrix1(double** A, double** B, size_t rows, size_t cols)
{
    double** sum = createMatrix(rows, cols);
    for (size_t r = 0; r < rows; ++r)
        for (size_t c = 0; c < cols; ++c)
            sum[r][c] = A[r][c] + B[r][c];
    return sum;
}
double** minusMatrix(double** A, double** B, size_t rows, size_t cols)
{
    double** difference = createMatrix(rows, cols);
    for (size_t r = 0; r < rows; ++r)
        for (size_t c = 0; c < cols; ++c)
            difference[r][c] = A[r][c] - B[r][c];
    return difference;
}
double** multMatrix2(double** A, double** B, size_t rowsA, size_t colsA, size_t colsB)
{
    double** M = createMatrix(rowsA, colsB);
    zeros(M, rowsA, colsB);
    for (size_t rowP = 0; rowP < rowsA; ++rowP)
        for (size_t colP = 0; colP < colsB; ++colP)
            for (size_t idx = 0; idx < colsA; ++idx)
                M[rowP][colP] += A[rowP][idx] * B[idx][colP];
    return M;
}
double& maximumMatrix(double** matrix, size_t rows, size_t cols)
{
    size_t r_max = 0;
    size_t c_max = 0;
    for (size_t r = 0; r < rows; ++r)
        for (size_t c = 0; c < cols; ++c)
            if (matrix[r][c] > matrix[r_max][c_max])
            {
                r_max = r;
                c_max = c;
            }
    return matrix[r_max][c_max];
}
double& minmaxMatrix(double** matrix, size_t rows, size_t cols)
{
    double** mins = new double* [rows];
    size_t min = 0;
    size_t max = 0;
    for (size_t r = 0; r < rows; ++r)
    {
        for (size_t c = 0; c < cols; ++c)
            if (matrix[r][c] < matrix[r][min]) min = c;
        mins[r] = &matrix[r][min];
    }
    for (size_t idx = 0; idx < rows; ++idx)
    {
        std::cout << *mins[idx] << " ";
        if (*mins[idx] > *mins[max]) max = idx;
    }
    return *mins[max];
}
void localMinimum(double** A, size_t rows, size_t columns) {
    double local_min = A[rows][0];
    size_t min = 0;
    for (size_t c = 0; c < columns; c++)
    {
        if (local_min > A[rows][c]) {
            local_min = A[rows][c];
            min = c;
        }
    }
    A[rows][min] = 0;
}
double** minor(double** matrix, size_t size, size_t row, size_t col)
{
    double** inter = createMatrix(size - 1, size - 1);
    size_t r = 0, c = 0;
    for (size_t row = 0; row < size; ++row)
        for (size_t col = 0; col < size; ++col)
        {
            if (col != col and row != row)
            {
                inter[r][c] = matrix[row][col];
                ++c;
            }
            if (c == size - 1)
            {
                c = 0;
                ++r;
            }
        }
    return inter;
}
double det(double** matrix, size_t size)
{
    double res = 0;
    if (size == 1)
        return matrix[0][0];
    if (size == 2)
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    if (size == 3)
        return matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[1][0] * matrix[2][1] * matrix[0][2] - matrix[0][2] * matrix[1][1] * matrix[2][0] - matrix[0][1] * matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][1] * matrix[0][0];
    else
    {
        size_t Column = 0;
        int sign = 1;
        for (size_t i = 1; i <= size; ++i)
        {
            double** algMinor = minor(matrix, size, 0, Column);
            res += sign * matrix[0][Column] * det(algMinor, size - 1);
            ++Column;
            sign *= -1;
            deleteMatrix(algMinor, size - 1, size - 1);
        }

    }
    return res;
}
double** inv(double** matrix, size_t size)
{
    double deter = det(matrix, size);
    double** minors = createMatrix(size, size);
    int sign = 1;
    for (size_t row = 0; row < size; ++row) {
        for (size_t col = 0; col < size; ++col) {
            double** currMinor = createMatrix(size - 1, size - 1);
            currMinor = minor(matrix, size, row, col);
            minors[row][col] = sign * det(currMinor, size - 1);
            sign *= -1;
            deleteMatrix(currMinor, size - 1, size - 1);
        }
    }
    minors = transpose(minors, size, size);
    for (size_t r = 0; r < size; ++r)
        for (size_t c = 0; c < size; ++c) minors[r][c] *= (1 / deter);
    return minors;
}
