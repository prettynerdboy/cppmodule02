#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
    this->_fixedPointValue= 0;
}

Fixed::Fixed(const Fixed &fixed)
{
    this->operator=(fixed);
}

Fixed::Fixed(const int nb)
{
    this->_fixedPointValue = nb << Fixed::decimalPoint;
}

Fixed::Fixed(const float nb)
{
    this->_fixedPointValue = (roundf(nb * (1 << Fixed::decimalPoint)));
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    if(this != &fixed)
        this->_fixedPointValue = fixed.getRawBits();
    return(*this);
}

std::ostream &operator<<(std::ostream &os,const Fixed &fixed)
{
    os << fixed.toFloat();
    return (os);
}

int Fixed::getRawBits(void) const 
{
    return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}

int Fixed::toInt(void) const
{
    return (this->_fixedPointValue >> Fixed::decimalPoint);
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointValue / (1 << this->decimalPoint));
}

// overload compare operators
bool Fixed::operator>(const Fixed &other) const
{
	return (this->_fixedPointValue > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->_fixedPointValue < other.getRawBits());
}
bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_fixedPointValue >= other.getRawBits());
}
bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_fixedPointValue <= other.getRawBits());
}
bool Fixed::operator==(const Fixed &other) const
{
	return (this->_fixedPointValue == other.getRawBits());
}
bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_fixedPointValue != other.getRawBits());
}

// overload math
Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	if (this->_fixedPointValue == 0 || other._fixedPointValue == 0)
	{
		std::cout << "Error";
		return (Fixed());
	}
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed &Fixed::operator++(void)
{
	this->_fixedPointValue++;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	this->_fixedPointValue--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp;

	tmp = Fixed(*this);
	this->_fixedPointValue++;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed	tmp;

	tmp = Fixed(*this);
	this->_fixedPointValue--;
	return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return ((a < b) ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return ((a > b) ? a : b);
}