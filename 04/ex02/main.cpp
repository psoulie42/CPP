#include "classes.h"
#include "Brain.hpp"
#include "wrongClasses.h"

int main()
{
	std::cout << "------------- TESTING LEAKS -------------" << std::endl;
	const AAnimal* kitty = new Cat(); // this works
	// Animal test; // this doesnt
	std::cout << std::endl;

	delete kitty;
	return 0;
}
