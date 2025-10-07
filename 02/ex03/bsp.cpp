#include "classFixed.hpp"
#include "classPoint.hpp"

// This tells us on which side of the a-b line point c stands.
// if a-b is vertical downwards:
// > 0 means "left" side
// < 0 means "right" side
// == 0 means colinear with a-b.
int whichSide(Point a, Point b, Point c)
{
	float res = (b.getX() - a.getX())*(c.getY() - a.getY()) - (b.getY() - a.getY())*(c.getX() - a.getX());

	if (res > 0)
		return 1;
	else if (res < 0)
		return -1;
	else
		return 0;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (whichSide(a, b, c) == 0)
	{
		std::cout << "You must give a valid triangle." << std::endl;
		return false;
	}
	if (whichSide(a, b, c) != whichSide(a, b, point) || whichSide(a, b, point) == 0)
		return false;
	if (whichSide(a, c, b) != whichSide(a, c, point) || whichSide(a, c, point) == 0)
		return false;
	if (whichSide(b, c, a) != whichSide(b, c, point) || whichSide(b, c, point) == 0)
		return false;
	return true;
}
