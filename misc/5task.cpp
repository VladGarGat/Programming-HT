#include <iostream>
int main()
{
    double a, b, c, d, x;
    std::cout << "Enter A, B, C, D for the first segment";
    std::cin >> a >> b >> c >> d;
    std::cout << "Enter x of the first segment";
    std::cin >> x;
    std::cout << "Point in the second segment is: " << c + (x - a) * (d - c) / (b - a) << std::endl;
}
