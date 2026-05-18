#include "classZombie.hpp"

void	Zombie::announce(void)
{
	std::cout << _name 
		<< ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie::Zombie()
{
	_name = "eggplant";
}

Zombie::Zombie(const Zombie& b)
{
	_name = b._name;
}

Zombie Zombie::operator=(const Zombie& r)
{
	_name = r._name;
	
	return *this;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " died." << std::endl;
}
