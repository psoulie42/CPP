#include "classZombie.hpp"

void	Zombie::giveName(std::string name)
{
	this->_name = name;
}

void	Zombie::announce(void)
{
	std::cout << _name 
		<< ": : BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie() {}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " died." << std::endl;
}
