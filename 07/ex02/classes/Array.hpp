#pragma once

#include <iostream>

template <typename T>
class Array
{
	private:
		T* _array;
		unsigned int _size;

	public:
		unsigned int size();

		T& operator[](int index) const;

		Array();
		Array(unsigned int size);
		Array(const Array&);
		Array& operator=(const Array&);
		~Array();

		class OutOfBoundsException: public std::exception
		{
			virtual const char* what() const throw();
		};
};

#include "Array.tpp"
