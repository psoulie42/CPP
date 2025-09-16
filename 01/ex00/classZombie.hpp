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

		Zombie(std::string name);
		~Zombie();
};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

#endif
