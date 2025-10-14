#include "Animal.hpp"

// ------------- MEMBER FUNCTIONS -------------

std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << "* generic animal sound *" << std::endl;
}

// ------------- CONSTRUCTORS & DESTRUCTORS -------------

Animal::Animal(): type("Generic animal")
{
	std::cout << this->type << " created" << std::endl;
}

Animal::Animal(const Animal& a)
{
	this->type = a.type;
	std::cout << "Animal copied" << std::endl;
}

Animal Animal::operator=(const Animal& a)
{
	if (this != &a)
	{
		this->type = a.type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destroyed" << std::endl;
}