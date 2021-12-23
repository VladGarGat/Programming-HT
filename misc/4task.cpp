#include <iostream>
int main() {
    float x = 0, epsilon;
    float result = 0, counter = 1, first_x;
    std::cout << "enter x" << std::endl;
    std::cin >> x; first_x = x;
    std::cout << "enter epsylon << std::endl;
    std::cin >> epsilon;
    while (counter > epsilon)
    {
        result += counter;
        counter *= x;
    }
    std::cout << "Result: " << result << std::endl;
    std::cout << "Function value" << 1. / (1. - first_x) << "\n";
}
