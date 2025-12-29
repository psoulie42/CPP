#ifndef DIAMONDTRAP_CLASS
# define DIAMONDTRAP_CLASS

#include "classScavTrap.hpp"
#include "classFragTrap.hpp"

# define BOLD "\033[1m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string _name;

	protected:
		int _energyPoints;
		int _attackDamage;
	
	public:
		void whoAmI();
		void storyTelling();
		using ScavTrap::attack;
		void status();

		DiamondTrap(std::string);
		DiamondTrap();
		DiamondTrap(const DiamondTrap&);
		DiamondTrap& operator=(const DiamondTrap&);
		~DiamondTrap();
};

#endif
