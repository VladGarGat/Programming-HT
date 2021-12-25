#include<iostream>
int main()
{
    int x, y;
    int k = 0;
    std::cout << "Enter the size of an array x, y:  ";
    std::cin >> x >> y;
    int** mtrx = new int* [x];
    for (int i = 0; i < x; ++i) mtrx[i] = new int[y];
    for (int i = 0; i < x; ++i)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < y; ++j)
            {
                ++k;
                mtrx[i][j] = k;
            }
        }
        else
        {
            for (int j = y - 1; j >= 0; --j)
            {
                ++k;
                mtrx[i][j] = k;
            }
        }
    }
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j) std::cout << mtrx[i][j] << " ";
        std::cout << "\n";
    }
}
