#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_fixedPointvalue=0;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constrctor called" << std::endl;
    this->operator=(fixed);
}

Fixed::Fixed(const int nb)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointvalue = nb << this->decimalPoint;
}

Fixed::Fixed(float nb)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointvalue = (roundf(nb * (1<<this->decimalPoint)));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &fixed)
        this->_fixedPointvalue = fixed.getRawBits();
    return (*this);
}

std::ostream &operator<<(std::ostream &os,const Fixed &fixed)
{
    os<<fixed.toFloat();
    return(os);
}

int Fixed::getRawBits(void) const
{
    return(this->_fixedPointvalue);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointvalue = raw;
}

int Fixed::toInt(void) const
{
    return(this->_fixedPointvalue >> this->decimalPoint);
}

float Fixed::toFloat(void) const
{
    return((float)this->_fixedPointvalue / (1<<this->decimalPoint));
}