#include "classZombie.hpp"

void	Zombie::announce(void)
{
	std::cout << _name 
		<< ": : BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " died." << std::endl;
}
