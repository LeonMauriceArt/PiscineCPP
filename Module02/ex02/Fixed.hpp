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
		//constructors
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		//copy constructor
		Fixed(const Fixed& f);
		//destructor
		~Fixed();

		//operators
			//assignement operator
		Fixed& operator=(const Fixed& f);
			//arithmetic operators
		Fixed operator+(const Fixed& f);
		Fixed operator-(const Fixed& f);
		Fixed operator*(const Fixed& f);
		Fixed operator/(const Fixed& f);
		// 	//comparison operators
		bool operator>(const Fixed &f);
		bool operator>=(const Fixed &f);
		bool operator<(const Fixed &f);
		bool operator<=(const Fixed &f);
		bool operator==(const Fixed &f);
		bool operator!=(const Fixed &f);
		// 	//increment operators
		Fixed operator++(void);
		Fixed operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		// insertion operator

		//function members
		static Fixed min(Fixed &fix1, Fixed &fix2);
		static Fixed min(const Fixed &fix1, const Fixed &fix2);
		static Fixed max(Fixed &fix1, Fixed &fix2);
		static Fixed max(const Fixed &fix1, const Fixed &fix2);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& f);

#endif