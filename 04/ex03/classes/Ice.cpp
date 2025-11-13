#include "Ice.hpp"

// ------------- ICE MEMBER FUNCTIONS -------------

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"
		<< std::endl;
	delete this;
}

Ice* Ice::clone() const
{
	return (new Ice);
}

// ------------- CONSTRUCTORS & DESTUCCTORS -------------

Ice::Ice(): AMateria("ice") {}

Ice::Ice(const Ice& b): AMateria("ice") {}

Ice Ice::operator=(const Ice& b)
{
	this->type = "ice";
	return *this;
}
