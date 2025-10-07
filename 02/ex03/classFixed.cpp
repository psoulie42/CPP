#include "classFixed.hpp"

//------------ MEMBER FUNCTIONS ------------

int Fixed::getRawBits() const
{
	return this->_val;
}

void	Fixed::setRawBits(int const raw)
{
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

//------------ CONSTRUCTORS ------------

Fixed::Fixed()
{
	this->_val = 0;
}
Fixed::Fixed(const int i)
{
	this->_val = i * (1 << 8);
}

Fixed::Fixed(const float f)
{
	this->_val = roundf(f * (1 << this->_frac));
}

Fixed::Fixed(const Fixed& fix)
{
	this->_val = fix._val;
}

Fixed& Fixed::operator=(const Fixed& fix)
{
	if (this != &fix)
	{
		this->_val = fix.getRawBits();
	}
	return *this;
}

//------------ COMPAISON OPERATOR OVERLOADS ------------

bool Fixed::operator<(const Fixed& fix) const
{
	if ((*this)._val < fix._val)
		return true;
	return false;
}
		
bool Fixed::operator>(const Fixed& fix) const
{
	if ((*this)._val > fix._val)
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed& fix) const
{
	if ((*this)._val <= fix._val)
		return true;
	std::cout << *this << " " << fix << std::endl;
	return false;
}
		
bool Fixed::operator>=(const Fixed& fix) const
{
	if ((*this)._val >= fix._val)
		return true;
	return false;
}
		
bool Fixed::operator==(const Fixed& fix) const
{
	if ((*this)._val == fix._val)
		return true;
	return false;
}
		
bool Fixed::operator!=(const Fixed& fix) const
{
	if ((*this)._val != fix._val)
		return true;
	return false;
}

//------------ ARITHMETIC OPERATOR OVERLOADS ------------

float Fixed::operator+(const Fixed& fix) const
{
	return this->toFloat() + fix.toFloat();
}

float Fixed::operator-(const Fixed& fix) const
{
	return this->toFloat() - fix.toFloat();
}
		
float Fixed::operator*(const Fixed& fix) const
{
	return this->toFloat() * fix.toFloat();
}

float Fixed::operator/(const Fixed& fix) const
{
	return this->toFloat() / fix.toFloat();
}

//------------ INCREMENTATION OPERATOR OVERLOADS ------------

Fixed Fixed::operator++()
{
	this->_val++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	++*this;
	return tmp;
}

Fixed Fixed::operator--()
{
	this->_val--;
	return *this;
}
		
Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	--*this;
	return tmp;
}

//------------ MIN & MAX CHECKS ------------

Fixed& Fixed::min(Fixed& l, Fixed& r)
{
	if (l < r)
		return l;
	return r;
}

const Fixed& Fixed::min(const Fixed& l, const Fixed& r)
{
	if (l < r)
		return l;
	return r;
}

Fixed& Fixed::max(Fixed& l, Fixed& r)
{
	if (l > r)
		return l;
	return r;
}

const Fixed& Fixed::max(const Fixed& l, const Fixed& r)
{
	if (l > r)
		return l;
	return r;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fix)
{
	os << fix.toFloat();
	return (os);
}

Fixed::~Fixed(){}
