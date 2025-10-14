#include "WrongDog.hpp"

// ------------- MEMBER FUNCTIONS -------------

void WrongDog::makeSound() const
{
	std::cout << this->type << " says woof" << std::endl;
}

// ------------- CONSTRUCTORS & DESTRUCTORS -------------

WrongDog::WrongDog()
{
	this->type = "WrongDog";
	std::cout << this->type << " created" << std::endl;
}

WrongDog::WrongDog(const WrongDog& c)
{
	this->type = c.type;
	std::cout << this->type << " copied" << std::endl;
}

WrongDog WrongDog::operator=(const WrongDog& WrongDog)
{
	if (this != &WrongDog)
	{
		this->type = WrongDog.type;
	}
	return *this;
}

WrongDog::~WrongDog()
{
	std::cout << this->type << " destroyed" << std::endl;
}
