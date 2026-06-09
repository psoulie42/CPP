#include "PmergeMe.hpp"

// ------------- MEMBER FUNCTIONS -------------

bool PmergeMe::isSorted()
{
	int ret = 0;

	ret = _vec[0].first;
	for (unsigned int i = 1; i < _vec.size(); i++)
	{
		if (ret > _vec[i].first)
			return false;
		ret = _vec[i].first;
	}

	return true;
}

float PmergeMe::efficiency()
{
	time_t now = std::time(NULL);

	return (std::difftime(now, _start));
}

bool PmergeMe::comp(int a, int b)
{
	_comps++;
	return (a > b);
}

void PmergeMe::startMergeVec(char **av)
{
	int i = 0;
	_start = (std::clock());

	av++;
	while (*av)
	{
		_vec.push_back(std::pair<int, int>(std::strtol(*av, NULL, 10), i++));
		av++;
	}

	std::cout << std::endl << "Running ford-johnson with vector" << std::endl;
	std::cout << "Initial sequence: ";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i].first << ' ';
	std::cout << std::endl;

	sort(_vec);
	std::cout << "Merge done with vector:" << std::endl;
	std::cout << "Sorted sequence: ";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i].first << ' ';
	std::cout << std::endl;

	if (isSorted())
		std::cout << "Sequence is sorted correctly! " << _comps << " comparisons made." << std::endl
			<< "Time taken with vector: " << std::clock() - _start / CLOCKS_PER_SEC << "µs." << std::endl;
	else
		std::cerr << "Merge failed at some point :(" << std::endl;
	_comps = 0;
}

int PmergeMe::jacob(int a, int b)
{
	if (b == 0)
		return 1;
	if (b == 1)
		return 3;
	return (2 * a + b);
}

int PmergeMe::dichotomix(int smol, std::vector<std::pair<int, int> >& nsort, int i)
{
	int max = i;
	int min = 0;

	if (smol < nsort[0].first)
		return (_comps++, 0);

	while (1)
	{
		i = (max + min) / 2;
		if (smol == nsort[i].first)
			return i;

		bool c = comp(smol, nsort[i].first);
		if (c == true)
			min = i;
		else
			max = i;
		if (max - min == 1)
			return (max);
	}
}

void PmergeMe::putvalinvectorbordel(std::pair<int, int> smol, int pos, std::vector<std::pair<int, int> >& nsort)
{
	std::vector<std::pair<int, int> >::iterator bordel = nsort.begin();
	
	while (pos > 0)
	{
		bordel++;
		pos--;
	}

	nsort.insert(bordel, smol);
}

std::vector<std::pair<int, int> > PmergeMe::insert(
		const std::vector<std::pair<int, int> >& smol, const std::vector<std::pair<int, int> >& beeg, std::vector<std::pair<int, int> >& nsort)
{
	int n = 0; // number corresponding to the std::paired index in beeg
	int a = 0; // jacobstahl low
	unsigned int b = 0; // jacobstahl high

	bool end = false;

	while (end == false)
	{
		if (b >= smol.size())
		{
			end = true;
			b = smol.size() - 1;
		}

		int j = b;
		while (j >= a)
		{
			unsigned int i = 0;
			while (i < beeg.size())
			{
				if (smol[j].second == beeg[i].first)
				{
					n = beeg[i].first;
					break;
				}
				i++;
			}
			if (i == beeg.size())
				i = nsort.size();
			else
			{
				i = 0;
				while (i < nsort.size() && n > nsort[i].first)
					i++;
			}
			putvalinvectorbordel(smol[j], dichotomix(smol[j].first, nsort, i), nsort);
			j--;
		}
		int tmp = b;
		b = jacob(a, b);
		if (b < 3)
			a = b;
		else
			a = tmp + 1;
	}
	return (nsort);
}

void PmergeMe::sort(std::vector<std::pair<int, int> >& main)
{
	_level--;

	if (main.size() < 2)
		return ;

	std::vector<std::pair<int, int> > beeg;
	std::vector<std::pair<int, int> > smol;

	for (size_t i = 1; i < main.size(); i += 2)
	{
		bool c = comp(main[i - 1].first, main[i].first);
		beeg.push_back(main[i - c]);
		smol.push_back(main[i - !c]);
		smol.back().second = beeg.back().first;
	}
	if (main.size() % 2 != 0)
	{
		smol.push_back(main.back());
		smol.back().second = _level;
	}

	std::vector<std::pair<int, int> > nsort(beeg);
	sort(nsort);

	main = insert(smol, beeg, nsort);
}

// ------------- CONSTRUCTORS -------------

PmergeMe::PmergeMe(): _start(std::time(NULL)), _comps(0), _level(0)  {}
