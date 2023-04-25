#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) / Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	if (a != b)
		std::cout << "a and b not the same" << std::endl;
	if (a == b)
		std::cout << "a and b are equal" << std::endl;
	if (a > b)
		std::cout << "a is superior to b" << std::endl;
	if (a >= b)
		std::cout << "a is superior or equal to b" << std::endl;
	if (a < b)
		std::cout << "a is inferior to b" << std::endl;
	if (a <= b)
		std::cout << "a is inferior or equal to b" << std::endl;
	std::cout << "Comparing a : " << a << " and b : " << b << std::endl;
	std::cout << "max = " << Fixed::max( a, b ) << std::endl;
	return 0;
}