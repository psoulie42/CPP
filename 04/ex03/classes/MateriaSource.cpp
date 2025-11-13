#include "MateriaSource.hpp"

// ------------- MATERIASOURCE MEMBER FUNCTIONS -------------

void MateriaSource::learnMateria(AMateria* materia)
{
    for (int i = 0; i < MAX_MATERIA; i++)
	{
        if (materias[i] == NULL)
		{
            materias[i] = materia;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
    for (int i = 0; i < MAX_MATERIA; i++)
	{
        if (materias[i] && materias[i]->getType() == type)
            return materias[i]->clone();
    }
    return NULL;
}

// ------------- CONSTRUCTORS & DESTRUCTORS -------------

MateriaSource::MateriaSource()
{
	for (int i = 0; i < MAX_MATERIA; i++)
		materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& b)
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (b.materias[i])
			materias[i] = b.materias[i] ? b.materias[i]->clone() : NULL;	
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& b)
{
	if (this != &b)
	{
		for (int i = 0; i < MAX_MATERIA; i++)
		{
			if (materias[i])
				delete materias[i];
			materias[i] = b.materias[i] ? b.materias[i]->clone() : NULL;	
		}
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_MATERIA; i++)
		if (materias[i])
			delete materias[i];
}
