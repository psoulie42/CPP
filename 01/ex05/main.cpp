#include <iostream>
#include <string>
#include "classHarl.hpp"

int	main()
{
	Harl harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("hello");
}
