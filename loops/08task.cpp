#include <iostream>
int main()
{
    int sum = 0, avg = 1, n;
    std::cout << "Enter number" << std::endl;
    std::cin >> n;
    while (n > 0)
    {
        sum += n % 10;
        avg *= n % 10;
        n /= 10;
    }
    std::cout << "The sum of number's digits is " << sum << "   The product is " << avg;
}
