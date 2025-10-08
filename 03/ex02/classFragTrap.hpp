#ifndef FRAGTRAP_CLASS
# define FRAGTRAP_CLASS

#include "classClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		void highFivesGuys();
		void attack(std::string);

		FragTrap(std::string name);
		~FragTrap();
};

#endif