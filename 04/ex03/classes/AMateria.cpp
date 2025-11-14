#include "AMateria.hpp"

// ------------- AMATERIA MEMBER FUNCTIONS -------------

void AMateria::use(ICharacter& target)
{
	std::cout << "* throws random bullshit at " << target.getName() << " *"
		<< std::endl;
}

const std::string& AMateria::getType() const
{
	return this->type;
}

// ------------- CONSTRUCTORS && DESTRUCTORS -------------

AMateria::AMateria(): type("unknown") {}

AMateria::AMateria(const std::string& type)
{
	this->type = type;
}

AMateria::AMateria(const AMateria& b)
{
	this->type = b.type;
}

AMateria::~AMateria() {}
