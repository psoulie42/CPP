#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cerr << "Error: This program needs an input file as argument to run!" << endl;
		return 1;
	}

	try
	{
		BitcoinExchange btc;
		btc.parseInput(av[1]);
		btc.parseCSV();
		btc.processFile();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << endl;
		return 1;
	}

	return 0;
}