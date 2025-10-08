#include "classScavTrap.hpp"

int main()
{
	ClapTrap c("Clappy");
	ScavTrap s("Scavvy");
	std::cout << std::endl;

	s.guardGate();
	std::cout << std::endl;

	c.attack("Scavvy");
	s.takeDamage(0);
	s.attack("Clappy");
	std::cout << std::endl;

	return (0);
}