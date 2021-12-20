#include <iostream>
#include <cmath>

bool righrec(double x, double y) {
    return (x >= 0 and y >= 0 and y <= -2 * (x - 1));
}
bool leftrec(double x, double y) {
    return (x <= 0 and y >= 0 and y <= 2 * (x + 1));
}
bool leftsemicircle(double x, double y) {
    return (x <= 0 and y <= 0 and y >= -sqrt(1 - pow((x + 1), 2)));
}
bool rigthsemicircle(double x, double y) {
    return (x >= 0 and y <= 0 and y >= -sqrt(1 - pow((x - 1), 2)));
}

int main() {
    double x, y;
    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "Enter y: ";
    std::cin >> y;
    if (righrec(x, y) or leftrec(x, y) or leftsemicircle(x, y) or rigthsemicircle(x, y))
        std::cout << "Target hit\n";
    else
        std::cout << "Miss\n";
}
