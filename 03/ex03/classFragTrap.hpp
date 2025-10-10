#ifndef FRAGTRAP_CLASS
# define FRAGTRAP_CLASS

#include "classClapTrap.hpp"

class FragTrap: public virtual ClapTrap
{
	protected:
		int _ownEnergyPoints;
		int _ownAttackDamage;
	
	public:
		void highFivesGuys();
		void attack(std::string);
		void fstatus();

		FragTrap(std::string name);
		~FragTrap();
};

#endif