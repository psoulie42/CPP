#include "classZombie.hpp"

int	main()
{
	Zombie* bwoooh;

	randomChump("bwaaah");
	bwoooh = newZombie("bwoooh");
	(*bwoooh).announce();
	delete bwoooh;
	return (0);
}