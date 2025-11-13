#ifndef AMATERIA_CLASS
# define AMATERIA_CLASS

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type;
	public:
		const std::string& getType() const;
		virtual void use(ICharacter& target);
		virtual AMateria* clone() const = 0;
		
		AMateria(const std::string& type);
		AMateria(const AMateria&);
		~AMateria();
};

#endif
