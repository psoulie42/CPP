#include "Ice.hpp"

// ------------- ICE MEMBER FUNCTIONS -------------

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target->name << " *"
		<< std::endl;
	delete this;
}

Ice* Ice::clone() const
{
	return (new Ice);
}

// ------------- CONSTRUCTORS & DESTUCCTORS -------------

Ice::Ice(): AMateria("ice") {}

Ice::Ice(const Ice& b): type(b->type) {}

Ice::operator=(const Ice& b)
{
	if (this != &b)
		type = b->type;
	return *this;
}
