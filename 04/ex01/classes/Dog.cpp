#include "Dog.hpp"

// ------------- MEMBER FUNCTIONS -------------

void Dog::makeSound() const
{
	std::cout << this->type << " says woof" << std::endl;
}

Brain* Dog::getBrain()
{
	return this->brain;
}

// ------------- CONSTRUCTORS & DESTRUCTORS -------------

Dog::Dog()
{
	this->brain = new Brain();
	this->type = "Dog";
	std::cout << this->type << " created" << std::endl;
}

Dog::Dog(const Dog& dog)
{
	this->brain = new Brain(*dog.brain);
	this->type = dog.type;
	std::cout << this->type << " copied" << std::endl;
}

Dog Dog::operator=(const Dog& dog)
{
	if (this != &dog)
	{
		this->brain = new Brain(*dog.brain);
		this->type = dog.type;
	}
	return *this;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << this->type << " destroyed" << std::endl;
}
