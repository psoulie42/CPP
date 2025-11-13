#pragma once

#include <string>
#include <iostream>
#include "IMateriaSource.hpp"

#define MAX_MATERIA 4

class MateriaSource: public IMateriaSource
{
	private:
		AMateria* materias[MAX_MATERIA];
	public:
		void learnMateria(AMateria*);
		AMateria* createMateria(const std::string& type);
		
		MateriaSource();
		MateriaSource(const MateriaSource&);
		MateriaSource& operator=(const MateriaSource&);
		~MateriaSource();
};
