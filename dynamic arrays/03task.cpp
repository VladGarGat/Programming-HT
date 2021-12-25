#include<iostream>
void SnakeArray(int** M, int n, bool d)
{
    int k = 1;
    for (int i = 0; i < n; ++i)
    {
        if (i % 2 == d)
            for (int j = 0; j < n; ++j, ++k)
                M[i][j] = k;
        else for (int j = n - 1; j >= 0; --j, ++k) M[i][j] = k;
    }
}
int main()
{
    int n;
    bool direction;
    std::cout << "Enter n "; std::cin >> n;
    std::cout << "fill direction 0 - rigth, 1 - left  "; std::cin >> direction;

    int** x = new int* [n];
    for (int i = 0; i < n; ++i)
        x[i] = new int[n];

    SnakeArray(x, n, direction);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j) std::cout << x[i][j] << " ";
        std::cout << "\n";
    }
}
