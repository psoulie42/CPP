#pragma once

#include <iostream>
#include <string>
#include "ICharacter.hpp"

#define INV_SIZE 4

class Character: public ICharacter
{
	public:
		std::string name;
		AMateria* inventory[INV_SIZE];

	private:
		const std::string& getName() const;
		void equip(AMateria*);
		void unequip(int i);
		void use(int i, ICharacter& target);
		AMateria* getMateria(int i) const;

		Character(const std::string& name);
		Character();
		Character(const Character&);
		Character operator=(const Character&);
		~Character();
};
