#include "AAnimal.hpp"

// ------------- MEMBER FUNCTIONS -------------

std::string AAnimal::getType() const
{
	return this->type;
}

// ------------- CONSTRUCTORS & DESTRUCTORS -------------

AAnimal::AAnimal(): type("Generic AAnimal")
{
	std::cout << this->type << " created" << std::endl;
}

AAnimal::AAnimal(const AAnimal& a)
{
	this->type = a.type;
	std::cout << "AAnimal copied" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destroyed" << std::endl;
}