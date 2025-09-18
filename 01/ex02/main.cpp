#include <iostream>
#include <string>

int	main()
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	ptrstr = &str;
	std::string&	refstr = str;

	std::cout << "address of str: " << &str << std::endl;
	std::cout << "ptrstr: " << ptrstr << std::endl;
	std::cout << "refstr: " << &refstr << std::endl;
	std::cout << std::endl;
	std::cout << "value of str: " << str << std::endl;
	std::cout << "value pointed to by ptrstr: " << *ptrstr << std::endl;
	std::cout << "value pointed to by refstr: " << refstr << std::endl;
	return 0;
}