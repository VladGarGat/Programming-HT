#include <iostream>
bool Function(double x, double y)
{
    return ((x * x + y * y - 1) * (x * x + y * y - 1) * (x * x + y * y - 1) - x * x * y * y * y <= 0);
}
int main()
{
    for (int y = 21; y >= 0; y--)
    {
        for (int x = 0; x < 41; x++)
        {
            if (Function(-1.5 + 3. / 41. * (double)x, -1.5 + 3. / 21. * (double)y))
                std::cout << "*";
            else
                std::cout << ".";
        }
        std::cout << std::endl;
    }
    return 0;
}
