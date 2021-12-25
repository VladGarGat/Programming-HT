#include <iostream>
#include<string>
std::string toright(int number, int spaces) {
    std::string result = std::to_string(number);
    int indent = 0;
    while (number > 0)
    {
        ++indent;
        number /= 10;
    }

    for (int i = 0; i < spaces - indent; ++i) result = " " + result;
    return result;
}
void fill_matrix(int n, int  m)
{

    int** mtrx = new int* [m];
    int* spaces = new int[m];

    for (int i = 0; i < m; ++i)
    {
        mtrx[i] = new int[n];
        int max = 0;
        for (int j = 0; j < n; ++j)
        {
            mtrx[i][j] = rand() % 99999;
            if (mtrx[i][j] > max) max = mtrx[i][j];
        }
        int indent = 0;
        while (max > 0)
        {
            ++indent;
            max /= 10;
        }
        spaces[i] = indent;
    }
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j)
        {
            std::cout << toright(mtrx[j][i], spaces[j]) << " ";
        }
        std::cout << std::endl;
    }
}
int main()
{
    std::cout << "Enter rows, columns ";
    int n, m;
    std::cin >> n >> m;
    fill_matrix(n, m);
}
