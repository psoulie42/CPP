#pragma once

#include <iostream>

template <typename T>
class Array
{
	private:
		T* _array;
		size_t _size;

	public:
		size_t size() const;

		T& operator[](int index) const;
		T& operator[](int index);

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
