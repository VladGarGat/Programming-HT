#include <iostream>
int main()
{
    int starttime[3];
    int endtime[3];
    std::cout << "Enter hours, mins, seconds " << std::endl;
    for (auto &i : starttime) std::cin >> i;
    std::cout << "Enter the end of a time span " << std::endl;
    for (auto &i : endtime) std::cin >> i;
    for (int i = 0; i < 3; i++) { std::cout << std::abs(starttime[i] - endtime[i]) << " "; }
}
