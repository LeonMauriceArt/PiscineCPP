#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixedpointnum;
		static const int fractional_bits = 8;

	public:
		Fixed(const int num);
		Fixed(const float num);
		Fixed();
		~Fixed();
		Fixed(const Fixed& f);
		Fixed& operator=(const Fixed& f);
		friend std::ostream& operator<<(std::ostream& out, const Fixed& f);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

#endif