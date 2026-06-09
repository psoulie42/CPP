#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <sys/time.h>
#include <cmath>
#include <ctime>

class PmergeMe
{
	private:
		std::vector<std::pair<int, int> > _vec;
		std::deque<std::pair<int, int> > _deq;
		clock_t _start;
		int _comps;
		int _level;
	
	public:
		bool isSorted();
		float efficiency();
		bool comp(int, int);
		int dichotomix(int smol, std::vector<std::pair<int, int> >& search, int index);
		int dichotomix(int smol, std::deque<std::pair<int, int> >& nsort, int i);
		void startMergeVec(char **av);
		void startMergeDeq(char **av);
		void putvalinvectorbordel(std::pair<int, int> smol, int pos, std::vector<std::pair<int, int> >& nsort);
		void putvalindequebordel(std::pair<int, int> smol, int pos, std::deque<std::pair<int, int> >& nsort);
		int jacob(int, int);
	
		void sort(std::vector<std::pair<int, int> >&);  // std::pair: val, index
		void sort(std::deque<std::pair<int, int> >& main);
		std::vector<std::pair<int, int> > insert(const std::vector<std::pair<int, int> >&, 
			const std::vector<std::pair<int, int> >&, std::vector<std::pair<int, int> >&);
		std::deque<std::pair<int, int> > insert(
			const std::deque<std::pair<int, int> >& smol, const std::deque<std::pair<int, int> >& beeg, std::deque<std::pair<int, int> >& nsort);


		PmergeMe();
};
