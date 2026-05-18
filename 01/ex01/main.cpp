#include "classZombie.hpp"

int	getN(void)
{
	int	n;

	std::cout 
		<< "How many zombies do you want?" << std::endl;
	while (true)
	{
		std::cin >> n;
		if (std::cin.eof())
			return -1;
		if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Please insert number: ";
			continue;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore();
			break;
		}
	}
	return (n);
}

int	main()
{
	Zombie* horde;
	int		n;
	std::string	name;

	n = getN();
	if (n == -1)
		return 1;
	std::cout
		<< "What do we call the zombies?" << std::endl;
	if (!std::getline(std::cin, name))
		return 1;
	horde = zombieHorde(n, name);
	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}
