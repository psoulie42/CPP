#ifndef AMATERIA_CLASS
# define AMATERIA_CLASS

#include <string>
#include <iostream>

class AMateria
{
	public:
		AMateria(const std::string& type);
		const std::string& getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
}

#endif