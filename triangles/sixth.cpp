#include <iostream>
int main()
{
    int height;
    std::cout << "Enter amount of half's height of rhomb: ";
    std::cin >> height;
    for (int i = 0; i < height; i++)
    {
        int stars = 2 * i + 1;
        for (int j = 0; j < 2 * height + 1; j++)
        {
            if (j == height - i || j == height + i) std::cout << "*";
            else std::cout << " ";
        }
        std::cout << std::endl;
    }
    for (int i = height; i >= 0; i--)
    {
        int stars = 2 * i + 1;
        for (int j = 0; j < 2 * height + 1; j++)
        {
            if (j == height - i || j == height + i) std::cout << "*";
            else std::cout << " ";
        }
        std::cout << std::endl;
    }
}
