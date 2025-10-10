#include "classScavTrap.hpp"
#include "classFragTrap.hpp"
#include "classDiamondTrap.hpp"

int main()
{
	DiamondTrap d("Shakra");
	std::cout << std::endl;

	d.whoAmI();
	d.storyTelling();
	std::cout << std::endl;

	return (0);
}
