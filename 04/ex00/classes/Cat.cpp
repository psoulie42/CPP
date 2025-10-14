#include "Cat.hpp"

// ------------- MEMBER FUNCTIONS -------------

void Cat::makeSound() const
{
	std::cout << this->type << " says meow" << std::endl;
}

// ------------- CONSTRUCTORS & DESTRUCTORS -------------

Cat::Cat()
{
	this->type = "Cat";
	std::cout << this->type << " created" << std::endl;
}

Cat::Cat(const Cat& c)
{
	this->type = c.type;
	std::cout << this->type << " copied" << std::endl;
}

Cat Cat::operator=(const Cat& cat)
{
	if (this != &cat)
	{
		this->type = cat.type;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << this->type << " destroyed" << std::endl;
}
