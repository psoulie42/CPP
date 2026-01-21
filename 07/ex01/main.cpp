#include <iostream>
#include "templates.h"

int main()
{
	// testing int tab
	int tab[] = {0, 1, 2, 3, 4};

	std::cout << "Base int tab: ";
	iter<int>(tab, 5, print);
	std::cout << std::endl;

	std::cout << "plusOne int tab: ";
	iter<int>(tab, 5, plusOne);
	iter<int>(tab, 5, print);
	std::cout << std::endl;

	// testing char tab
	char str[] = {'H', 'E', 'L', 'L', 'O'};

	std::cout << "Base char tab: ";
	iter<char>(str, 5, print);
	std::cout << std::endl;

	std::cout << "plusOne char tab: ";
	iter<char>(str, 5, plusOne);
	iter<char>(str, 5, print);
	std::cout << std::endl;

	return 0;
}
