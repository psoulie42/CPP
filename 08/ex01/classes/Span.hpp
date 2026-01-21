#pragma once

#include <iostream>
#include <limits>
#include <vector>

using std::vector;

class Span
{
	private:
		unsigned int _n;
		vector<int> _data;

	public:
		void addNumber(int);
		unsigned int longestSpan();
		unsigned int shortestSpan();

	Span();
	Span(unsigned int N);
	Span(const Span&);
	Span& operator=(const Span&);
	~Span();

	class NotEnoughNumbersException: public std::exception
	{
		virtual const char* what() const throw();
	};
	class ContainerFullException: public std::exception
	{
		virtual const char* what() const throw();
	};
};
