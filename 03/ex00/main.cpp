#include "classClapTrap.hpp"

int main()
{
	clapTrap c("Clappy");
	clapTrap a("Claps");
	std::cout << std::endl;

	// Using both ClapTraps energy points
	c.attack("Clappy");
	a.takeDamage(0);
	a.beRepaired(10);
	c.attack("Clappy");
	a.takeDamage(0);
	a.beRepaired(10);
	c.attack("Clappy");
	a.takeDamage(0);
	a.beRepaired(10);
	c.attack("Clappy");
	a.takeDamage(0);
	a.beRepaired(10);
	c.attack("Clappy");
	a.takeDamage(0);
	a.beRepaired(10);
	c.attack("Clappy");
	a.takeDamage(0);
	a.beRepaired(10);
	c.attack("Clappy");
	a.takeDamage(0);
	a.beRepaired(10);
	c.attack("Clappy");
	a.takeDamage(0);
	a.beRepaired(10);
	c.attack("Clappy");
	a.takeDamage(0);
	a.beRepaired(10);
	c.attack("Clappy");
	a.takeDamage(0);
	a.beRepaired(10);
	std::cout << std::endl;

	// This one should tell you both are exhausted

	c.attack("Albert");
	a.beRepaired(10);
	std::cout << std::endl;

	return (0);
}