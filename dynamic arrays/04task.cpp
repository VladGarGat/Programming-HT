#include<iostream>
#include<cmath>
double mysqrt(double x, double eps = 1e-6)
{
	float x1 = 1.0, x2 = 1.0;
	do
	{
		x1 = x2;
		x2 = (x1 + x / x1) / 2;
		std::cout << x2 << " " << x1 << std::endl;
	} while (fabs((x1 - x2)) > eps);
	return x2;
}
