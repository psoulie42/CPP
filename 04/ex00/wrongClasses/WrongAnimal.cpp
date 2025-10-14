#include "WrongAnimal.hpp"

// ------------- MEMBER FUNCTIONS -------------

std::string WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "THIS IS THE WRONG SOUND!!!" << std::endl;
}

// ------------- CONSTRUCTORS & DESTRUCTORS -------------

WrongAnimal::WrongAnimal(): type("Generic Wronganimal")
{
	std::cout << this->type << " created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& a)
{
	this->type = a.type;
	std::cout << "WrongAnimal copied" << std::endl;
}

WrongAnimal WrongAnimal::operator=(const WrongAnimal& a)
{
	if (this != &a)
	{
		this->type = a.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destroyed" << std::endl;
}