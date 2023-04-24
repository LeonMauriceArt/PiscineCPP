#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed c(7.5f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	c.setRawBits(5126);
	std::cout << "c tests : rawbits = " << c.getRawBits() << std::endl;
	std::cout << "a is " << a << " as float" << std::endl;
	std::cout << "b is " << b << " as float" << std::endl;
	std::cout << "c is " << c << " as float" << std::endl;
	std::cout << "d is " << d << " as float" << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	
	std::cout << (float)(10860 >> 8) << std::endl;
	return 0;
}