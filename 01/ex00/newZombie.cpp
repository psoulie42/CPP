#include "classZombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *neo;

	neo = new Zombie(name);
	return neo;
}
