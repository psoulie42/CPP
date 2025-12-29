#include "classClapTrap.hpp"

int main()
{
	ClapTrap c("Claps");
	ClapTrap a("Clappy");
	std::cout << std::endl;

	std::cout << "----- Using both ClapTraps energy points -----" << std::endl;
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

	std::cout << "----- This one should tell you both are exhausted -----" << std::endl;
	c.attack("Albert");
	a.beRepaired(10);
	std::cout << std::endl;

	return (0);
}