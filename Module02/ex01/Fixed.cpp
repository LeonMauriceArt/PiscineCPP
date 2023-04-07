#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fixedpointnum = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedpointnum = num * (1 << this->fractional_bits);
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedpointnum = roundf(num * (1 << this->fractional_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(f.getRawBits());
}

Fixed &Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->setRawBits(f.getRawBits());
	return (*this);
}

float Fixed::toFloat(void) const
{
	return ((float)this->fixedpointnum / (1 << this->fractional_bits));
}

int Fixed::toInt(void) const
{
	return (this->fixedpointnum / (1 << this->fractional_bits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}

int Fixed::getRawBits(void) const
{
	return(this->fixedpointnum);
}

void Fixed::setRawBits(int const raw)
{
	this->fixedpointnum = raw;
}
