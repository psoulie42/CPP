#ifndef CURE_CLASS
# define CURE_CLASS

#include <string>
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria
{
	public:
		Cure* clone() const;
		void use(ICharacter& target);
		
		Cure(const std::string& type);
		Cure();
		Cure(const Cure&);
		Cure& operator=(const Cure&);
		~Cure();
};

#endif