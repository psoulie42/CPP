#ifndef POINT_CLASS
# define POINT_CLASS

#include "classFixed.hpp"
#include <iostream>
#include <string>

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		const Fixed getX() const;
		const Fixed getY() const;

		Point();
		Point(float, float);
		Point(const Point&);
		Point& operator=(const Point&);
		~Point();
};


bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif