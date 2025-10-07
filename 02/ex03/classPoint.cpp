#include "classPoint.hpp"

//------------ GETTERS ------------

const Fixed Point::getX() const
{
	return this->_x;
}

const Fixed Point::getY() const
{
	return this->_y;
}

//------------ CONSTRUCTORS & ASSIGNMENT ------------

Point::Point(): _x(0), _y(0) {}

Point::Point(float x, float y): _x(x), _y(y) {}

Point::Point(const Point& p): _x(p._x), _y(p._y) {}

Point& Point::operator=(const Point&)
{
	return *this;
}

//------------ DESTRUCTOR ------------

Point::~Point() {}
