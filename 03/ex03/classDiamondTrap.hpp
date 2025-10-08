#ifndef DIAMONDTRAP_CLASS
# define DIAMONDTRAP_CLASS

#include "classScavTrap.hpp"
#include "classFragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string _name;
	
	public:
		void whoAmI();

		DiamondTrap(std::string);
		~DiamondTrap();
};

#endif