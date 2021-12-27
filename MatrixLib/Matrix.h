#pragma once

double** createMatrix(size_t rows, size_t cols);
void deleteMatrix(double** matrix, size_t rows, size_t cols);
void inputMatrix(double** matrix, size_t rows, size_t cols);
double** inputFileMatrix(char const* filename, size_t& rows, size_t& cols);
void printMatrix(double** matrix, size_t rows, size_t cols);
void zeros(double** matrix, size_t rows, size_t cols);
void ones(double** matrix, size_t rows, size_t cols);
void fill(double** matrix, size_t rows, size_t cols, double val = 0);
double** linspace(size_t length);
double** transpose(double** matrix, size_t rows, size_t cols);
void rotate180(double** matrix, size_t rows, size_t cols);
double& findMinimum(double** matrix, size_t rows, size_t cols);
double& minmaxMatrix(double** matrix, size_t rows, size_t cols);
void mixMatrix( double** matrix, size_t rows, size_t cols, size_t k1, size_t k2);
void randMatrix(double** matrix, size_t rows, size_t cols,double minval = 0, double maxval = 1);

double** multMatrix1(double lambda, double** M, size_t rows, size_t cols);
double** plusMatrix(double** A, double** B, size_t rows, size_t cols);
double** minusMatrix(double** A, double** B, size_t rows, size_t cols);
double** multMatrix2(double** A, double** B, size_t rowsA, size_t columnsA, size_t columnsB);
double& maximumMatrix(double** matrix, size_t rows, size_t columns);
double& minmaxMatrix(double** M, size_t rows, size_t columns);
void localMinimum(double** A, size_t row, size_t columns);
double** minor(double** matrix, size_t size, size_t row, size_t col);
double det(double** matrix, size_t size);
double** inv(double** matrix, size_t size);
