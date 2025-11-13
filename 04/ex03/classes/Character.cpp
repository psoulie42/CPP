#include "Character.hpp"

// ------------- CHARACTER MEMBER FUNCTIONS -------------

const std::string& Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria* newMateria)
{
	int i = 0;
	while (i < INV_SIZE && inventory[i])
		i++;
	if (i == INV_SIZE)
	{
		std::cout << name << "tried to equip a new Materia but their inventory was full."
			<< std::endl;
		return;
	}
	inventory[i] = newMateria;
}

void Character::unequip(int i)
{
	if (i >= 0 && i < INV_SIZE)
		inventory[i] = NULL;
}

void Character::use(int i, ICharacter& target)
{
	if (i >= 0 && i < INV_SIZE && inventory[i])
	{
		inventory[i]->use(target);
	}
}

AMateria* Character::getMateria(int i) const
{
	if (i >= 0 && i < INV_SIZE)
		return inventory[i];
	return NULL;
}

// ------------- CONSTRUCTORS & DESTRUCTORS -------------

Character::Character(const std::string& name): name(name)
{
	for (int i = 0; i < INV_SIZE; i++)
		inventory[i] = NULL;
}

Character::Character(): name("Bob")
{
	for (int i = 0; i < INV_SIZE; i++)
		inventory[i] = NULL;
}

Character::Character(const Character& b): name(b.name)
{
	for (int i = 0; i < INV_SIZE; i++)
		inventory[i] = b.inventory[i] ? b.inventory[i]->clone() : NULL;
}

Character Character::operator=(const Character& b)
{
	if (this != &b)
	{
		name = b.name;
		for (int i = 0; i < INV_SIZE; i++)
		{
			if (inventory[i])
				delete inventory[i];
			inventory[i] = b.inventory[i] ? b.inventory[i]->clone() : NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < INV_SIZE; i++)
		if (inventory[i])
			delete inventory[i];
}
