#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac <= 2)
		return (cout << "You need to run the program with a sequence of numbers to sort!" << endl, 1);

	try
	{
		PmergeMe merge;
		merge.startMergeVec(av);
		merge.startMergeDeq(av);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
