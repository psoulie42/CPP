#include "Cat.hpp"

// ------------- MEMBER FUNCTIONS -------------

void Cat::makeSound() const
{
	std::cout << this->type << " says meow" << std::endl;
}

Brain* Cat::getBrain()
{
	return this->brain;
}

// ------------- CONSTRUCTORS & DESTRUCTORS -------------

Cat::Cat()
{
	this->brain = new Brain();
	this->type = "Cat";
	std::cout << this->type << " created" << std::endl;
}

Cat::Cat(const Cat& cat)
{
	this->brain = new Brain(*cat.brain);
	this->type = cat.type;
	std::cout << this->type << " copied" << std::endl;
}

Cat Cat::operator=(const Cat& cat)
{
	if (this != &cat)
	{
		this->type = cat.type;
		this->brain = new Brain(*cat.brain);
	}
	return *this;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << this->type << " destroyed" << std::endl;
}
