#include <iostream>
#include <cmath>
int main()
{
	double a, b, c;
	std::cout << "Enter a b c :\n";
	std::cin >> a >> b >> c;
	double d = b * b - 4 * a * c;
	if (d < 0) std::cout << "No roots";
	else if (d == 0) std::cout << "There's only 1 root" << -b/(2*a);
	else if (d > 0)
	{
		double x1 = (-b + sqrt(d)) / 2 / a;
		double x2 = (-b - sqrt(d)) / 2 / a;
		std::cout << "There are 2 roots: " << x1 << " and " << x2;
	}
}
