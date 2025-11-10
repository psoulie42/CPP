#ifndef ICE_CLASS
# define ICE_CLASS

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Ice: AMateria
{
	protected:
		const std::string& type;
	public:
		Ice(const std::string& type);
		const std::string& getType() const;

		virtual AMateria* clone() const;
}

#endif