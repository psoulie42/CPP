#include "WrongDog.hpp"

// ------------- MEMBER FUNCTIONS -------------

void WrongDog::makeSound() const
{
	std::cout << this->type << " says woof" << std::endl;
}

Brain* WrongDog::getBrain()
{
	return this->brain;
}



// ------------- CONSTRUCTORS & DESTRUCTORS -------------

WrongDog::WrongDog()
{
	this->brain = new Brain();
	this->type = "WrongDog";
	std::cout << this->type << " created" << std::endl;
}

WrongDog::WrongDog(const WrongDog& d)
{
	this->brain = d.brain;
	this->type = d.type;
	std::cout << this->type << " copied" << std::endl;
}

WrongDog WrongDog::operator=(const WrongDog& WrongDog)
{
	if (this != &WrongDog)
	{
		this->brain = WrongDog.brain;
		this->type = WrongDog.type;
	}
	return *this;
}

WrongDog::~WrongDog()
{
	std::cout << this->type << " destroyed" << std::endl;
}
