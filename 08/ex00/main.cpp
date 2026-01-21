#include "easyfind.hpp"

#include <vector>
#include <deque>

using std::cout;
using std::endl;
using std::vector;
using std::deque;

template <typename T>
static void displayContainer(T& container)
{
	cout << "{";
	for (unsigned int i = 0; i < container.size(); i++)
		cout << " " << container[i];
	cout << " }" << endl;
}

int main()
{
	vector<int> v(5);
	vector<int>::iterator vit;
	deque<int> d(5);
	deque<int>::iterator dit;

	for (unsigned int i = 0; i < v.size(); i++)
	{
		v[i] = i;
		d[i] = i;
	}

	cout << "Vector: ";
	displayContainer(v);
	cout << "Deque: ";
	displayContainer(d);
	cout << endl << "Use easyfind to search a 3:" << endl;

	try
	{
		cout << "Try in vector: ";
		vit = easyfind<vector<int> >(v, 3);
		cout << "Found!" << endl;
	}
	catch (std::exception& e)
	{
		cout << e .what()<< endl;
		return (1);
	}

	try
	{
		cout << "Try in deque: ";
		dit = easyfind<deque<int> >(d, 3);
		cout << "Found!" << endl;
	}
	catch (std::exception& e)
	{
		cout << e .what()<< endl;
		return (1);
	}

	cout << "Replace the 3 with a 42 in the vector using the iterator:" << endl;
	*vit = 42;
	*dit = 42;
	cout << "New vector: ";
	displayContainer(v);
	cout << "New deque: ";
	displayContainer(d);
	cout << endl;

	cout << "Use easyfind to search a 400:" << endl;
	try
	{
		cout << "Try in vector: ";
		easyfind<vector<int> >(v, 3);
		cout << "Found!" << endl;
	}
	catch (std::exception& e)
	{
		cout << e.what() << endl;
	}

	try
	{
		cout << "Try in deque: ";
		easyfind<deque<int> >(d, 3);
		cout << "Found!" << endl;
	}
	catch (std::exception& e)
	{
		cout << e.what() << endl;
	}

	return (0);
}
