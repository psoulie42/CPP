#include "class.HumanA.hpp"

void	HumanA::attack()
{
	if (this->_weapon.getType().empty())
		std::cout << this->_name << "Has no weapon!" << std::endl;
	else
		std::cout << this->_name << " attacks with " 
			<< (this->_weapon).getType() << "." << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon)
	: _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}
