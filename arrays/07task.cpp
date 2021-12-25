#include <iostream>
int main()
{
    int N;
    std::cin >> N;
    int i = 1, floor = 1;
    while ((N - i) > 0)
    {
        for (int j = 1; j <= i; ++j)
        {

            if ((N - i) > 0)
            {
                ++floor;
                N -= i;
            }
        }
        ++i;
    }
    std::cout << floor << ", " << N;
}
