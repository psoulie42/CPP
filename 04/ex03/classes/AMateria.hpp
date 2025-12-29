#ifndef AMATERIA_CLASS
# define AMATERIA_CLASS

#include <string>
#include <iostream>

class AMateria;

#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type;
	public:
		const std::string& getType() const;
		virtual void use(ICharacter& target);
		virtual AMateria* clone() const = 0;
		
		AMateria();
		AMateria(const std::string& type);
		AMateria(const AMateria&);
		virtual ~AMateria();
};

#endif
