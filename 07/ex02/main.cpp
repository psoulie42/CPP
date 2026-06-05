#include <iostream>
#include "Array.hpp"

int main(int, char**)
{
	try
	{
		std::cout << "Creating array with default constructor..." << std::endl;
		Array<char> empty;
		std::cout << "Array size: " << empty.size() << std::endl << std::endl;
	
		std::cout << "Creating array with uint constructor..." << std::endl;
		Array<int> total(10);
		std::cout << "Array contents: ";
		for (size_t i = 0; i < total.size(); i++)
			std::cout << (total[i] = i);
		std::cout << std::endl << std::endl;

		std::cout << "Testing assignment operator depth..." << std::endl;
		Array<int> copy = total;
		std::cout << "Copy: ";
		for (size_t i = 0; i < copy.size(); i++)
			std::cout << copy[i];
		std::cout << std::endl;
		
		//modifying copy (mustnt affect total)
		std::cout << "Modified copy: ";
		for (size_t i = 0; i < copy.size(); i++)
			std::cout << ++copy[i];
		std::cout << std::endl;
		
		std::cout << "Original array: ";
		for (size_t i = 0; i < total.size(); i++)
			std::cout << total[i];
		std::cout << std::endl << std::endl;

		std::cout << "Testing Array with complex type (string): ";
		Array<std::string> strs(3);
		strs[0] = "Hello ";
		strs[1] = "World ";
		strs[2] = "!";
		for (size_t i = 0; i < strs.size(); i++)
			std::cout << strs[i];
		std::cout << std::endl << std::endl;


		std::cout << "Testing out of bounds: ";
		total[11] = -1;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	
	return 0;
}
