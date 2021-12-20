#include <iostream>

int main()
{
    int n = 26;
    while (n > 25)
    {
        std::cout << "Input height of triangle not more than 25\n";
        std::cin >> n;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int k = 0; k < i; ++k)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    return 0;
}
