#include "classZombie.hpp"

int	getN(void)
{
	int	n;

	while (true)
	{
		std::cout 
			<< "How many zombies do you want?" << std::endl;
		std::cin >> n;
		if (std::cin.fail())
		{
			std::cout << "Please insert number." << std::endl;
			std::cin.clear();
			std::cin.ignore();
			continue;
		}
		else
			break;
	}
	return (n);
}

std::string getName(void)
{
	std::string name;

	std::cout 
		<< "What do we call the zombies?" << std::endl;
	std::cin >> name;
	return name;
}

int	main()
{
	Zombie* horde;
	int		n;
	std::string	name;

	n = getN();
	name = getName();
	horde = zombieHorde(n, name);
	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}
