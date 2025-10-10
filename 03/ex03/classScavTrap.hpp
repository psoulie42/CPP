#ifndef SCAVTRAP_CLASS
# define SCAVTRAP_CLASS

# include <iostream>
# include <string>
# include "classClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	protected:
		int _ownEnergyPoints;
		int _ownAttackDamage;
	
	public:
		void guardGate();
		void attack(const std::string&);
		void sstatus();

		ScavTrap(std::string);
		~ScavTrap();
};

#endif