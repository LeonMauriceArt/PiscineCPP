#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Fixed class created" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Fixed class destroyed" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor" << std::endl;
	this->number = f.number;
}

Fixed &Fixed::operator=(const Fixed &f)
{
	std::cout << "Assignement operator" << std::endl;
	this->number = f.number;
	return (*this);
}