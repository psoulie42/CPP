#ifndef ICE_CLASS
# define ICE_CLASS

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Ice: AMateria
{
	public:
		Ice* clone() const;
		void use(Icharacter& target);
		
		Ice(const std::string& type);
		Ice(const Ice&);
		operator=(const Ice&);
		~Ice();
};

#endif