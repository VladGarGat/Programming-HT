#include<iostream>
int main()
{
    int element, n, array[999] = {};
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> element;
        array[i] = element;
    }
    int d = array[2] - array[1];
    for (int i = 1; i < n; ++i)
    {
        if ((array[i + 2] - array[i + 1]) != d)
        {
            std::cout << 0;
            break;
        }
        else std::cout << d; break;
    }
}
