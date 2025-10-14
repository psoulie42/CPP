#include "Dog.hpp"

// ------------- MEMBER FUNCTIONS -------------

void Dog::makeSound() const
{
	std::cout << this->type << " says woof" << std::endl;
}

// ------------- CONSTRUCTORS & DESTRUCTORS -------------

Dog::Dog()
{
	this->type = "Dog";
	std::cout << this->type << " created" << std::endl;
}

Dog::Dog(const Dog& c)
{
	this->type = c.type;
	std::cout << this->type << " copied" << std::endl;
}

Dog Dog::operator=(const Dog& Dog)
{
	if (this != &Dog)
	{
		this->type = Dog.type;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << this->type << " destroyed" << std::endl;
}
