#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int number;
		static const int bits;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& f);
		Fixed& operator=(const Fixed& f);
};

#endif