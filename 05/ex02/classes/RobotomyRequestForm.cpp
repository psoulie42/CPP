#include "RobotomyRequestForm.hpp"

// ------------- RRF MEMBER FUNCTIONS -------------

void RRF::_performAction() const
{
	int robotomy = rand() % 2;

	if (robotomy)
		std::cout << _target << " has been robotomised successfully." << std::endl;
	else
		std::cout << "Robotomy failed. You'll get it next time." << std::endl;
}

// ------------- CONSTRUCTORS & DESTRUCTORS -------------

RRF::RRF(): AForm("Robotomy Request Form", 72, 45), _target("your old Peugeot 206") {}

RRF::RRF(std::string target): AForm("Robotomy Request Form", 72, 45), _target(target) {}

RRF::RRF(const RRF& b): AForm("Robotomy Request Form", 72, 45), _target(b._target) {}

RRF::~RRF() {}

// -------------- OPERATOR OVERLOADS -------------

RRF& RRF::operator=(const RRF& r)
{
	this->_target = r._target;
	std::cout << "These forms dont really support assignment operators, please create them another way." << std::endl;
	return *this;
}
