#include <iostream>
int main()
{
    std::cout << "Enter amount of half's height of rhomb: ";
    int num, i;
    std::cin >> num;

    for (i = 1; i <= num; ++i)
    {
        for (int j = 0; j < num - i; j++) std::cout << " ";
        for (int k = 0; k < i; k++) std::cout << "* ";
        std::cout << std::endl;

    }
    i -= 2;
    for (; i >= 0; --i)
    {
        for (int j = 0; j < num - i; ++j) std::cout << " ";
        for (int k = 0; k < i; ++k) std::cout << "* ";
        std::cout << std::endl;

    }
    return 0;
}
