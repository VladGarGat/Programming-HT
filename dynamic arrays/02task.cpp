#include <iostream>
#include<string>
std::string leftalignment(int num, int spaces)
{
    std::string res = std::to_string(num);
    int indent = 0;
    do
    {
        ++indent;
        num /= 10;
    } while (num);
    int d = spaces - indent;
    for (int i = 0; i < d; ++i) res += " ";
    return res;
}
void Indent()
{
    int x, y;
    std::cin >> x >> y;

    int** mtrx = new int* [y];
    int* spaces = new int[y];

    for (int i = 0; i < y; ++i)
    {
        mtrx[i] = new int[x];
        int max = 0;
        for (int j = 0; j < x; ++j)
        {
            mtrx[i][j] = rand() % 100000;
            if (mtrx[i][j] > max) max = mtrx[i][j];
        }
        int indent = 0;
        do
        {
            ++indent;
            max /= 10;
        } while (max);
        spaces[i] = indent;
    }
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j) std::cout << leftalignment(mtrx[j][i], spaces[j]) << " ";
        std::cout << std::endl;
    }
}
int main()
{
    std::cout << "Enter the size of an array ";
    Indent();
}
