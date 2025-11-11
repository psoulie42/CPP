#include "Cure.hpp"

// ------------- CURE MEMBER FUNCTIONS -------------

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target->name << "'s wounds *"
		<< std::endl;
	delete this;
}

Cure* Cure::clone() const
{
	return (new Cure);
}

// ------------- CONSTRUCTORS & DESTUCCTORS -------------

Cure::Cure(): AMateria("cure") {}

Cure::Cure(const Cure& b): type(b->type) {}

Cure::operator=(const Cure& b)
{
	if (this != &b)
		type = b->type;
	return *this;
}
