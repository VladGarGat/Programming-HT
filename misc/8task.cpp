#include <iostream>
int main()
{
    int i = 1;
    while (i != 100)
    {
        if (i % 3 == 0) std::cout << "Foo";
        if (i % 5 == 0) std::cout << "Bar";
        if (i % 3 != 0 and i % 5 != 0) std::cout << i;
        std::cout << "\n"; ++i;
    }
}
