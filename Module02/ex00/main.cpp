#include "Fixed.hpp"


int main()
{
	Fixed t1, t2;
	t2 = t1;
	Fixed t3 = t1;
	return 0;
}

// int main(void)
// {
// 	Fixed a;
// 	Fixed b(a);
// 	Fixed c;
// 	c = b;
// 	std::cout << a.getRawBits() << std::endl;
// 	std::cout << b.getRawBits() << std::endl;
// 	std::cout << c.getRawBits() << std::endl;
// 	return 0;
// }