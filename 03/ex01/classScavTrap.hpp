#ifndef SCAVTRAP_CLASS
# define SCAVTRAP_CLASS

# include <iostream>
# include <string>
# include "classClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		void guardGate();
		void attack(const std::string&);

		ScavTrap(std::string);
		~ScavTrap();
};

#endif