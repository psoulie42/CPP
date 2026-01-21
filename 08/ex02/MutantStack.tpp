#include "MutantStack.hpp"

// ------------- MEMBER FUNCTIONS -------------

// the underlying container in stack is called c
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

// ------------- CONSTRUCTORS & DESTRUCTORS ------------

template <typename T>
MutantStack<T>::MutantStack() {}


template <typename T>
MutantStack<T>::MutantStack(const MutantStack& b): stack<T>(b) {}


template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& r)
{
	if (this == &r)
		return *this;

	stack<T>::operator=(r);
	return *this;
}


template <typename T>
MutantStack<T>::~MutantStack() {}
