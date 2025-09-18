#include <iostream>
#include <string>
#include <fstream>

int	main(int ac, char **av)
{
	std::string		filename, frepl, s1, s2, read;
	std::fstream	fin, fout;
	int				pos;

	if (ac != 4)
		return (std::cout << "Program requires 3 arguments.\n", 1);
	filename = av[1];
	s1 = av[2];
	s2 = av[3];

	fin.open(filename, std::ios::in);
	if (!fin.is_open())
		return (std::cout << "Error while opening file " << filename << std::endl, 1);
	frepl = filename + ".replace";
	fout.open(frepl, std::ios::out);
	if (!fout.is_open())
		return (fin.close(), std::cout << "Error while opening file " << frepl << std::endl, 1);
	
	while (std::getline(fin, read))
	{
		while ((pos = read.find(s1)) != (int)std::string::npos)
		{
			read.erase(pos, s1.size());
			read.insert(pos, s2);
		}
		fout << read + "\n";
	}

	fin.close();
	fout.close();
	return 0;
}
