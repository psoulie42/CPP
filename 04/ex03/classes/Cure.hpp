#ifndef CURE_CLASS
# define CURE_CLASS

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Cure: AMateria
{
	public:
		Cure* clone() const;
		void use(Icharacter& target);
		
		Cure(const std::string& type);
		Cure(const Cure&);
		operator=(const Cure&);
		~Cure();
};

#endif