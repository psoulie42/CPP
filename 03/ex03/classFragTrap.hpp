#ifndef FRAGTRAP_CLASS
# define FRAGTRAP_CLASS

#include "classClapTrap.hpp"

class FragTrap: public virtual ClapTrap
{
	protected:
		int _energyPoints;
		int _attackDamage;
	
	public:
		void highFivesGuys();
		void attack(std::string);
		void fstatus();

		FragTrap(std::string name);
		FragTrap();
		FragTrap(const FragTrap&);
		FragTrap& operator=(const FragTrap&);
		~FragTrap();
};

#endif