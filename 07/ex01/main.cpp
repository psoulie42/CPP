#include <iostream>
#include "templates.h"

int main()
{
	// testing int tab
	int tab[] = {0, 1, 2, 3, 4};

	std::cout << "Base int tab: ";
	::iter(tab, 5, ::print);
	std::cout << std::endl;

	std::cout << "plusOne int tab: ";
	::iter(tab, 5, ::plusOne);
	::iter(tab, 5, ::print);
	std::cout << std::endl;

	// testing char tab
	char str[] = {'H', 'E', 'L', 'L', 'O'};

	std::cout << "Base char tab: ";
	::iter(str, 5, ::print);
	std::cout << std::endl;

	std::cout << "plusOne char tab: ";
	::iter(str, 5, ::plusOne);
	::iter(str, 5, ::print);
	std::cout << std::endl;

	// testing const char tab
	const char constr[] = {'B', 'A', 'N', 'A', 'N', 'A'};
	std::cout << "const char tab: ";
	::iter(constr, 6, ::print);
	std::cout << std::endl;

	return 0;
}
