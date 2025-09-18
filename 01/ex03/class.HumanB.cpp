#include "class.HumanB.hpp"

void	HumanB::attack(void)
{
	if (!this->_weapon)
		std::cout << this->_name << " has no weapon!" << std::endl;
	else
		std::cout << this->_name << " attacks with " 
			<< (*this->_weapon).getType() << "." << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

HumanB::HumanB(std::string name)
	: _name(name), _weapon(NULL) {}

HumanB::~HumanB() {}
