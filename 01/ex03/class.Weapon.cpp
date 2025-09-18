#include "class.Weapon.hpp"

std::string&	Weapon::getType(void)
{
	return this->_type;
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

Weapon::Weapon(std::string weaponType)
	: _type(weaponType) {}

Weapon::~Weapon() {}
