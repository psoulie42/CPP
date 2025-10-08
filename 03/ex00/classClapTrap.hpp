#ifndef CLAPTRAP_CLASS
# define CLAPTRAP_CLASS

# include <string>
# include <iostream>

class clapTrap
{
	private:
		std::string _name;
		int	_hitPoints;
		int	_energyPoints;
		int	_attackDamage;

		public:
			void attack(const std::string&);
			void takeDamage(unsigned int);
			void beRepaired(unsigned int);

			clapTrap(std::string);
			~clapTrap();
};

#endif