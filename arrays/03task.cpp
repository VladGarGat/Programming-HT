#include <iostream>
int main()
{
    int number;
    int length = 0;
    char result_to_16[128] = "";
    char number_16[128] = "";
    char answer[128] = "";

    std::cout << "Enter decimal number "; std::cin >> number;
    std::cout << "Hexademical version of your number is " << answer;

    while (number != 0)
    {
        length++;
        if ((number % 16) < 10) { answer[length] = '0' + number % 16; }
        else answer[length] = char((number % 16) + 55);
        number /= 16;
    }
    for (int i = length; i >= 1; --i) std::cout << answer[i];
}
