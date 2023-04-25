#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fixedpointnum = 0;
}

Fixed::Fixed(const int num)
{
	this->fixedpointnum = num * (1 << this->fractional_bits);
}

Fixed::Fixed(const float num)
{
	this->fixedpointnum = roundf(num * (1 << this->fractional_bits));
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &f)
{
	this->setRawBits(f.getRawBits());
}

Fixed &Fixed::operator=(const Fixed &f)
{
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

Fixed Fixed::operator+(const Fixed &f)
{
	return (Fixed(this->toFloat() + f.toFloat()));
}

Fixed Fixed::operator-(const Fixed &f)
{
	return (Fixed(this->toFloat() - f.toFloat()));
}

Fixed Fixed::operator*(const Fixed &f)
{
	return (Fixed(this->toFloat() * f.toFloat()));
}

Fixed Fixed::operator/(const Fixed &f)
{
	return (Fixed(this->toFloat() / f.toFloat()));
}

bool Fixed::operator>(const Fixed &f)
{
	if (this->fixedpointnum > f.fixedpointnum)
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &f)
{
	if (this->fixedpointnum >= f.fixedpointnum)
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &f)
{
	if (this->fixedpointnum < f.fixedpointnum)
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &f)
{
	if (this->fixedpointnum <= f.fixedpointnum)
		return (true);
	return (false);
}
bool Fixed::operator==(const Fixed &f)
{
	if (this->fixedpointnum == f.fixedpointnum)
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &f)
{
	if (this->fixedpointnum != f.fixedpointnum)
		return (true);
	return (false);
}

Fixed Fixed::operator++(void)
{
	this->fixedpointnum = this->fixedpointnum + 1;
	return (*this);
}

Fixed Fixed::operator--(void)
{
	this->fixedpointnum = this->fixedpointnum - 1;
	return (*this);
}

//post increment
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->fixedpointnum = this->fixedpointnum + 1;
	return (tmp);
}

//post decrement
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->fixedpointnum = this->fixedpointnum - 1;
	return (tmp);
}

Fixed Fixed::min(Fixed &fix1, Fixed &fix2)
{
	if (fix1.fixedpointnum < fix2.fixedpointnum)
		return (fix1);
	return (fix2);
}

Fixed Fixed::min(const Fixed &fix1, const Fixed &fix2)
{
	if (fix1.fixedpointnum < fix2.fixedpointnum)
		return (fix1);
	return (fix2);
}

Fixed Fixed::max(Fixed &fix1, Fixed &fix2)
{
	if (fix1.fixedpointnum > fix2.fixedpointnum)
		return (fix1);
	return (fix2);
}

Fixed Fixed::max(const Fixed &fix1, const Fixed &fix2)
{
	if (fix1.fixedpointnum > fix2.fixedpointnum)
		return (fix1);
	return (fix2);
}