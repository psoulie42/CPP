#include "classFixed.hpp"
#include "classPoint.hpp"

int main( void ) 
{
	Point a(1, 0);
	Point b(2, 3.5);
	Point c(3, 1);
	Point p1(1, 2);
	Point p2(2, 1);

	std::cout << bsp(a, b, c, p1) << std::endl;
	std::cout << bsp(a, b, c, p2) << std::endl;
	return 0;
}
