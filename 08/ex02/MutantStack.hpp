#pragma once

#include <stack>

template <typename T>
class MutantStack: public std::stack<T> 
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin();
		iterator end();

		MutantStack();
		MutantStack(const MutantStack&);
		MutantStack& operator=(const MutantStack&);
		~MutantStack();
};

#include "MutantStack.tpp"
