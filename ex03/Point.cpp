#include "Point.hpp"

Point::Point()
{
}
Point::Point(float x, float y) : _x(x), _y(y)
{
}
Point::Point(const Point &point)
{
	this->operator=(point);
}

Point &Point::operator=(const Point &point)
{
	if (this != &point)
	{
		(Fixed) this->_x = point.getX();
		(Fixed) this->_y = point.getY();
	}
	return (*this);
}
Point::~Point()
{
}

Fixed Point::getX() const
{
	return (this->_x);
}

Fixed Point::getY() const
{
	return (this->_y);
}