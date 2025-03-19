#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int _fixedPointvalue;
        static const int decimalPoint = 8;
    public:
        Fixed();
        Fixed(const int nb);
        Fixed(const float nb);
        Fixed(const Fixed &fixed);
        Fixed &operator= (const Fixed &fixed);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);
        int toInt(void) const;
        float toFloat(void) const;
};
#endif

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
//staticを使うと全てのオブジェクトで同じ値を参照してくれるので修正