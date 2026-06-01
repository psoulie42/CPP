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
	av++;
	while (*av)
	{
		_vec.push_back(pair<int, int>(std::strtol(*av, NULL, 10), i++));
		av++;
	}

	cout << endl << "Running ford-johnson with vector" << endl;
	cout << "Initial sequence: ";
	for (size_t i = 0; i < _vec.size(); i++)
		cout << _vec[i].first << ' ';
	cout << endl;

	_start = (std::clock());
	sort(_vec);
	cout << "Merge done with vector:" << endl;
	cout << "Sorted sequence: ";
	for (size_t i = 0; i < _vec.size(); i++)
		cout << _vec[i].first << ' ';
	cout << endl;

	int n = _vec.size();
	if (isSorted())
		cout << "Sequence is sorted correctly! " << _comps << " comparisons made." << endl
			<< "Optimal number of comparisons: " << static_cast<int>(n * std::log2(n) - 1.415 * n) << endl
			<< "Time taken with vector: " << std::clock() - _start / CLOCKS_PER_SEC << "µs." << endl;
	else
		cout << "Merge failed at some point :(" << endl;
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

int PmergeMe::dichotomix(int smol, vector<pair<int, int> >& nsort, int i)
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

void PmergeMe::putvalinvectorbordel(pair<int, int> smol, int pos, vector<pair<int, int> >& nsort)
{
	vector<pair<int, int> >::iterator bordel = nsort.begin();
	
	while (pos > 0)
	{
		bordel++;
		pos--;
	}

	nsort.insert(bordel, smol);
}

vector<pair<int, int> > PmergeMe::insert(
		const vector<pair<int, int> >& smol, const vector<pair<int, int> >& beeg, vector<pair<int, int> >& nsort)
{
	int n = 0; // number corresponding to the paired index in beeg
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

void PmergeMe::sort(vector<pair<int, int> >& main)
{
	_level--;

	if (main.size() < 2)
		return ;

	vector<pair<int, int> > beeg;
	vector<pair<int, int> > smol;

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

	vector<pair<int, int> > nsort(beeg);
	sort(nsort);

	main = insert(smol, beeg, nsort);
}

// ------------- CONSTRUCTORS -------------

PmergeMe::PmergeMe(): _start(std::time(NULL)), _comps(0), _level(0)  {}
