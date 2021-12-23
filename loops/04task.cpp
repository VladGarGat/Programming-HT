#include <iostream>
#include <cmath>
int main()
{
    int n = 0;
    double epsilon, sum = 0, i = 1.;
    std::cout << "Enter epsilon: ";
    std::cin >> epsilon;

    while ((1 / ((double)n * 2. + 1)) > epsilon)
    {
        sum += i / ((double)n * 2. + 1);
        i *= -1; n += 1;
    }
    std::cout << "pi is " << 4. * sum << "\n";
}
