#include <iostream>
int main()
{
	double R;
  std::cout << "Enter R";
	std::cin >> R;
	double sum = 0;
	for (double y = -(double)R; y <= (double)R; y += 1)
	{
		for (double x = -(double)R; x <= (double)R; x += 1)
		{
			if ((x * x + y * y) <= R * R) ++sum;
		}
	}
	std::cout << sum;
}
