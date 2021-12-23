#include <iostream>
int main() {
	float x, y, R, r;
	std::cout << "Enter х, у";
	std::cin >> x >> y;
	std::cout << "Enter R, r";
	std::cin >> R >> r;
	int a = x * x + y * y;
	if ((a < R*R) and (a > r*r))
	{
		std::cout << "into";
	}
	else {
		std::cout << "out of";
	}
}
