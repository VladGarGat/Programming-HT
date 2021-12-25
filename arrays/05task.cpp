#include <iostream>
int main()
{
    int a[10];
    int N, i;
    std::cin >> N;
    for (i = 0; i < N; ++i) std::cin >> a[i];
    int summax = a[0] + a[1], k = 1;
    for (i = 2; i < N; ++i)
    {
        if ((a[i - 1] + a[i]) > summax)
        {
            summax = a[i - 1] + a[i];
            k = i;
        }
    }
    std::cout << a[k - 1] << a[k];
}
