#ifndef ZOMBIE_CLASS
# define ZOMBIE_CLASS

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string	_name;
	public:
		void	announce(void);
		void	giveName(std::string name);

		Zombie();
		~Zombie();
};

Zombie* zombieHorde(int n, std::string name);
Zombie* killHorde(int n, Zombie* horde);

#endif
