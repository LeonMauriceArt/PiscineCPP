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
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& f);
		Fixed();
		//destructor
		~Fixed();

		//operators
			//assignement operator
		Fixed& operator=(const Fixed& f);
			//arithmetic operators
		Fixed operator+(const Fixed& f);
		Fixed operator-(const Fixed& f);
		Fixed operator*(const Fixed& f)const;
		// Fixed operator/(const Fixed& f);
		// 	//comparison operators
		// bool operator>(const Fixed &f);
		// bool operator>=(const Fixed &f);
		// bool operator<(const Fixed &f);
		// bool operator<=(const Fixed &f);
		// bool operator==(const Fixed &f);
		// bool operator!=(const Fixed &f);
		// 	//increment operators
		// Fixed operator++(void);
		// Fixed operator--(void);
		// Fixed operator++(int);
		// Fixed operator--(int);

		// insertion operator
		friend std::ostream& operator<<(std::ostream& out, const Fixed& f);

		//function members
		static int& min(int& fix1, int& fix2);
		static int& min(const int &fix1, const int &fix2);
		static int& max(int &fix1, int &fix2);
		static int& max(const int &fix1, const int &fix2);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

#endif