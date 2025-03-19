#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int _fixedPointValue;
        static const int decimalPoint = 8;
    public:
        Fixed();
        Fixed(const int nb);
        Fixed(const float nb);
        Fixed(const Fixed &fixed);
        Fixed &operator=(const Fixed &fixed);
        ~Fixed();
        Fixed operator+(const Fixed &other)const;
        Fixed operator-(const Fixed &other)const;
        Fixed operator*(const Fixed &other)const;
        Fixed operator/(const Fixed &other)const;
        bool operator>(const Fixed &other)const;
        bool operator<(const Fixed &other)const;
        bool operator>=(const Fixed &other)const;
        bool operator<=(const Fixed &other)const;
        bool operator==(const Fixed &other)const;
        bool operator!=(const Fixed &other)const;
        Fixed &operator++(void);
        Fixed &operator--(void);
        Fixed operator++(int);
        Fixed operator--(int);
        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a , const Fixed &b);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        int toInt(void) const;
        float toFloat(void) const;
};

std::ostream &operator<<(std::ostream &oS, const Fixed &fixed);

#endif 