#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
    std::cout << "Default constructor called" <<std::endl;
    this->_fixedPointvalue = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    this->operator=(fixed);
}

Fixed::~Fixed()
{
    std::cout <<"Destructor called" << std::endl;
} 

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &fixed)
        this->_fixedPointvalue = fixed.getRawBits();
    return (*this);
}
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPointvalue);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointvalue= raw;       
}