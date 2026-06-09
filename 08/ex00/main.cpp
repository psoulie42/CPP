#include "easyfind.hpp"

#include <vector>
#include <deque>

int main()
{
	std::vector<int> v(5);
	std::vector<int>::iterator vit;
	std::deque<int> d(5);
	std::deque<int>::iterator dit;

	for (unsigned int i = 0; i < v.size() - 1; i++)
	{
		v[i] = i;
		d[i] = i;
	}
	v[v.size() - 1] = 2;
	d[d.size() - 1] = 2;

	std::cout << "vector: ";
	displayContainer(v);
	std::cout << "deque: ";
	displayContainer(d);
	std::cout << std::endl << "Use easyfind to search a 3:" << std::endl;

	try
	{
		std::cout << "Try in vector: ";
		vit = easyfind<std::vector<int> >(v, 3);
		std::cout << "Found!" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what()<< std::endl;
		return (1);
	}

	try
	{
		std::cout << "Try in deque: ";
		dit = easyfind<std::deque<int> >(d, 3);
		std::cout << "Found!" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what()<< std::endl;
		return (1);
	}

	try
	{
		std::cout << "Replace the 3 with a 42 in the vector using the iterator:" << std::endl;
		*vit = 42;
		*dit = 42;
		std::cout << "New vector: ";
		displayContainer(v);
		std::cout << "New deque: ";
		displayContainer(d);
		std::cout << std::endl;

		std::cout << "Check if it returns first occurrence: " << std::endl;
		vit = easyfind(v, 2);
		dit = easyfind(d, 2);
		std::cout << "Number found in vector: " << *vit << ", next: " << *++vit << std::endl;
		std::cout << "Number found in deque: " << *dit << ", next: " << *++dit << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "Use easyfind to search a 3:" << std::endl;
	try
	{
		std::cout << "Try in vector: ";
		easyfind<std::vector<int> >(v, 3);
		std::cout << "Found!" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "Try in deque: ";
		easyfind<std::deque<int> >(d, 3);
		std::cout << "Found!" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
