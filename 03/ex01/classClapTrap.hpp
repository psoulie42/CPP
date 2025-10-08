#ifndef CLAPTRAP_CLASS
# define CLAPTRAP_CLASS

# include <string>
# include <iostream>

class ClapTrap
{
	protected:
		std::string _name;
		int	_hitPoints;
		int	_energyPoints;
		int	_attackDamage;

	public:
		void attack(const std::string&);
		void takeDamage(unsigned int);
		void beRepaired(unsigned int);

		ClapTrap(std::string);
		~ClapTrap();
};

#endif