#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int	main(void)
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);
	Point p(3, 3);

	if (bsp(a, b, c, p))
	{
		std::cout << "The point is inside the triangle." << std::endl;
	}
	else
	{
		std::cout << "The point is outside the triangle." << std::endl;
	}

	return (0);
}