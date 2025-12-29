#ifndef SCAVTRAP_CLASS
# define SCAVTRAP_CLASS

# include <iostream>
# include <string>
# include "classClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	private:
		bool _gateKeeping;

	protected:
		int _energyPoints;
		int _attackDamage;
	
	public:
		void guardGate();
		void attack(const std::string&);
		void sstatus();

		ScavTrap(std::string);
		ScavTrap();
		ScavTrap(const ScavTrap&);
		ScavTrap& operator=(const ScavTrap&);
		~ScavTrap();
};

#endif