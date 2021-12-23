#include <iostream>
int main()
{
    int n = 0, step = 0, max = 1;
    std::cout << "Enter n: "; std::cin >> n;
    while (n != 1)
    {
        if (n > max) max = n;
        else max += 0;
        if (n % 2 == 0) n /= 2;
        else n = (n * 3) + 1;
        ++step;
    }
    std::cout << "max = " << max << ", steps = " << step << "\n";
    return 0;
}
