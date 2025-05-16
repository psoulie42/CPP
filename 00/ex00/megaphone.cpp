#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	std::string str;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	str = av[1];
	for (int i = 2; i < ac; i++)
		str += av[i];
	for (int i = 0; str[i]; i++)
		str[i] = (char)toupper(str[i]);
	std::cout << str << std::endl;
	return (0);
}
