#include "Point.hpp"

float	area(Point const &a, Point const &b, Point const &c)
{
	return (((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())
				+ b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())
				+ c.getX().toFloat() * (a.getY().toFloat()
					- b.getY().toFloat())) / 2.0f));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	totalArea;
	float	area1;
	float	area2;
	float	area3;

	totalArea = area(a, b, c);
	area1 = area(point, b, c);
	area2 = area(a, point, c);
	area3 = area(a, b, point);
	return (totalArea == area1 + area2 + area3);
}