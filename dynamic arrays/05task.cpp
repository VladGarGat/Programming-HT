#include <iostream>
int main()
{
    int x, y, top = 0, left = 0, counter = 1;
    std::cout << "rows ";  std::cin >> x;
    std::cout << "columns ";  std::cin >> y;
    int bottom = x;
    int right = y;
    int** mtrx = new int* [x];
    for (int i = 0; i < x; ++i) mtrx[i] = new int[x];

    while (counter < (x * y))
    {

        for (int i = left; i < right; ++i, ++counter) mtrx[top][i] = counter;
        ++top;

        for (int i = top; i < bottom; ++i, ++counter) mtrx[i][right - 1] = counter;
        --right;

        for (int i = right - 1; i > left; --i, ++counter) mtrx[bottom - 1][i] = counter;
        --bottom;

        for (int i = bottom; i >= top; --i, ++counter) mtrx[i][left] = counter;
        ++left;
    }
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j) std::cout << mtrx[i][j] << "    ";
        std::cout << "\n";
    }
}
