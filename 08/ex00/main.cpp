#include "easyfind.hpp"

#include <vector>
#include <deque>

int main()
{
	std::vector<int> v(5);
	std::vector<int>::iterator vit;
	std::deque<int> d(5);
	std::deque<int>::iterator dit;

	for (unsigned int i = 0; i < v.size(); i++)
	{
		v[i] = i;
		d[i] = i;
	}

	std::cout << "std::vector: ";
	displayContainer(v);
	std::cout << "std::deque: ";
	displayContainer(d);
	std::cout << std::endl << "Use easyfind to search a 3:" << std::endl;

	try
	{
		std::cout << "Try in std::vector: ";
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
		std::cout << "Try in std::deque: ";
		dit = easyfind<std::deque<int> >(d, 3);
		std::cout << "Found!" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e .what()<< std::endl;
		return (1);
	}

	std::cout << "Replace the 3 with a 42 in the std::vector using the iterator:" << std::endl;
	*vit = 42;
	*dit = 42;
	std::cout << "New std::vector: ";
	displayContainer(v);
	std::cout << "New std::deque: ";
	displayContainer(d);
	std::cout << std::endl;

	std::cout << "Use easyfind to search a 400:" << std::endl;
	try
	{
		std::cout << "Try in std::vector: ";
		easyfind<std::vector<int> >(v, 3);
		std::cout << "Found!" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "Try in std::deque: ";
		easyfind<std::deque<int> >(d, 3);
		std::cout << "Found!" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
