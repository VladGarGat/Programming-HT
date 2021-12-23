#include<iostream>
int main()
{
    int x, a = 1;
    std::cout << "Enter number " << std::endl;
    std::cin >> x;
    while (a <= x) a *= 2;
    std::cout << "Binary version of this number is " << std::endl;
    while (a > 1)
    {
        a /= 2;
        if (x >= a)
        {
            std::cout << "1";
            x -= a;
        }
        else std::cout << "0";
    }
    std::cout << "\n";
}
