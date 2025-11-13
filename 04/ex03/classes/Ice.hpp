#ifndef ICE_CLASS
# define ICE_CLASS

#include <string>
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria
{
	public:
		Ice* clone() const;
		void use(ICharacter& target);
		
		Ice();
		Ice(const Ice&);
		Ice operator=(const Ice&);
		~Ice();
};

#endif