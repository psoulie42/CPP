#include "classScavTrap.hpp"
#include "classFragTrap.hpp"

int main()
{
	FragTrap f("Fraggy");
	ScavTrap s("Scavvy");
	std::cout << std::endl;

	FragTrap y;

	y = f;
	y.highFivesGuys();
	s.guardGate();
	s.attack(f.getName());
	f.attack(s.getName());
	std::cout << std::endl;


	std::cout << std::endl;

	return (0);
}