#include "AMateria.hpp"

// ------------- AMATERIA MEMBER FUNCTIONS -------------

const std::string& AMateria::getType() const
{
	return this->type;
}

// ------------- CONSTRUCTORS && DESTRUCTORS -------------

AMateria::AMateria(std::string type)
{
	this->type = type;
}

AMateria::AMateria(const AMateria& b)
{
	this->type = b->type;
}
