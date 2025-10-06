#include "classFixed.hpp"

//------------ MEMBER FUNCTIONS ------------

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_val;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_val = raw;
}

float	Fixed::toFloat() const
{
	return ((float)this->_val / (1 << this->_frac));
}

int	Fixed::toInt() const
{
	return (roundf(this->_val / (1 << this->_frac)));
}

//------------ CONSTRUCTORS & DESTRUCTORS ------------

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_val = 0;
}
Fixed::Fixed(const int i)
{
	std::cout << "Integer constructor called" << std::endl;
	this->_val = i * (1 << 8);
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_val = roundf(f * (1 << this->_frac));
}

Fixed::Fixed(const Fixed& fix)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_val = fix._val;
}

Fixed Fixed::operator=(const Fixed& fix)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fix)
	{
		this->_val = fix.getRawBits();
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fix)
{
	os << fix.toFloat();
	return (os);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
