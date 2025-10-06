#include "classFixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	

	std::cout << "------------ TESTING INCREMENTATION ------------\n" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << std::endl;

	std::cout << "------------ TESTING COMPARISON OPERATORS ------------\n" << std::endl;
	Fixed c = a;
	std::cout << "This should alternate between 1 and 0:" << std::endl; 
	std::cout << (a < b) << std::endl;
	std::cout << (a > b) << std::endl;
	std::cout << (a <= c) << std::endl;
	std::cout << (a >= b) << std::endl;
	std::cout << (a == c) << std::endl;
	std::cout << (a == b) << std::endl;
	std::cout << (a != b) << std::endl;
	std::cout << (a != c) << std::endl;
	std::cout << std::endl;

	std::cout << "------------ TESTING ARITHMETIC OPERATORS ------------\n" << std::endl;
	std::cout << (a + b) << std::endl;
	std::cout << (a - b) << std::endl;
	std::cout << (a * b) << std::endl;
	std::cout << (a / b) << std::endl;
	std::cout << std::endl;


	std::cout << "------------ TESTING MAX & MIN ------------\n" << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << std::endl;

	return 0;
}
