#include "classDiamondTrap.hpp"

// -------------- MEMBER FUNCTIONS ------------



// ------------- CONSTRUCTOR & DESTRUCTOR -------------

DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	
}