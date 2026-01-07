#include "PresidentialPardonForm.hpp"

// ------------- PPF MEMBER FUNCTIONS -------------

void PPF::_performAction() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblerox." << std::endl;
}

// ------------- CONSTRUCTORS & DESTRUCTORS -------------

PPF::PPF(): AForm("Presidential Pardon Form", 25, 5), _target("your old Peugeot 206") {}

PPF::PPF(std::string target): AForm("Presidential Pardon Form", 25, 5), _target(target) {}

PPF::PPF(const PPF& b): AForm("Presidential Pardon Form", 25, 5), _target(b._target) {}

PPF::~PPF() {}

// -------------- OPERATOR OVERLOADS -------------

PPF& PPF::operator=(const PPF& r)
{
	this->_target = r._target;
	std::cout << "These forms dont really support assignment operators, please create them another way." << std::endl;
	return *this;
}
