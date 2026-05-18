#include "classFixed.hpp"
#include "classPoint.hpp"

int main( void ) 
{
	Point a(1, 0);
	Point b(2, 3.5);
	Point c(3, 1);
	Point p1(1, 2);
	Point p2(2, 1);
	Point p3(1, 0);

	std::cout << "Testing with a point outside of the triangle: " << std::endl;
	std::cout << bsp(a, b, c, p1) << std::endl;
	std::cout << std::endl;
	std::cout << "Testing with a point inside of the triangle: " << std::endl;
	std::cout << bsp(a, b, c, p2) << std::endl;
	std::cout << std::endl;
	std::cout << "Testing with a point on a vertex of the triangle: " << std::endl;
	std::cout << bsp(a, b, c, p3) << std::endl;
	return 0;
}
