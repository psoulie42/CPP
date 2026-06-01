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

using std::cout;
using std::string;
using std::endl;
using std::vector;
using std::deque;
using std::exception;
using std::pair;

class PmergeMe
{
	private:
		vector<pair<int, int> > _vec;
		deque<pair<int, int> > _deq;
		clock_t _start;
		int _comps;
		int _level;
	
	public:
		bool isSorted();
		float efficiency();
		bool comp(int, int);
		int dichotomix(int smol, vector<pair<int, int> >& search, int index);
		int dichotomix(int smol, deque<pair<int, int> >& nsort, int i);
		void startMergeVec(char **av);
		void startMergeDeq(char **av);
		void putvalinvectorbordel(pair<int, int> smol, int pos, vector<pair<int, int> >& nsort);
		void putvalindequebordel(pair<int, int> smol, int pos, deque<pair<int, int> >& nsort);
		int jacob(int, int);
	
		void sort(vector<pair<int, int> >&);  // pair: val, index
		void sort(deque<pair<int, int> >& main);
		vector<pair<int, int> > insert(const vector<pair<int, int> >&, 
			const vector<pair<int, int> >&, vector<pair<int, int> >&);
		deque<pair<int, int> > insert(
			const deque<pair<int, int> >& smol, const deque<pair<int, int> >& beeg, deque<pair<int, int> >& nsort);


		PmergeMe();
};
