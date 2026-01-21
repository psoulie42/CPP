#pragma once

#include "Array.hpp"

// ------------- ARRAY MEMBER FUNCTIONS -------------

template <typename T>
unsigned int Array<T>::size()
{
	return _size;
}

// ------------- EXCEPTIONS -------------

template<class T>	
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Index is out of bounds!");
}

// ------------- OPERATOR OVERLOADS -------------

template <typename T>
T& Array<T>::operator[](int index) const
{
	if (static_cast<const unsigned int>(index) >= _size || index < 0)
		throw OutOfBoundsException();
	return _array[index];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& r)
{
	if (this == &r)
		return *this;


	_array = new T[r._size];
	
	for (int i = 0; i < r._size; i++)
		_array[i] = r._array[i];
	_size = r._size;

	return *this;
}

// ------------- CONSTRUCTORS & DESTRUCTORS --------------

template <typename T>
Array<T>::Array(): _size(0)
{
	_array = NULL;
}

template <typename T>
Array<T>::Array(unsigned int size): _size(size)
{
	_array = new T[_size];
}

template <typename T>
Array<T>::Array(const Array& b): _size(b._size)
{
	_array = new T[_size];
	
	for (unsigned int i = 0; i < b._size; i++)
		_array[i] = b._array[i];
}

template <typename T>
Array<T>::~Array()
{
	delete [] _array;
}
