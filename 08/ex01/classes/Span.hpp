#pragma once

#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>

using std::vector;

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _data;

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

		template <typename Iterator>
		void    addRange(Iterator begin, Iterator end)
		{
			size_t    count = static_cast<size_t>(std::distance(begin, end));

			if (_data.size() + count > _n)
				throw ContainerFullException();
			_data.insert(_data.end(), begin, end);
		}
};
/* 
#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <iterator>
# include <cstdlib>
# include <exception>

class Span
{
public:
    class SpanFullException : public std::exception
    {
    public:
        virtual const char*    what() const throw();
    };

    class NoSpanException : public std::exception
    {
    public:
        virtual const char*    what() const throw();
    };

    Span(unsigned int n);
    Span(Span const & other);
    Span &    operator=(Span const & other);
    ~Span();

    void    addNumber(int number);


    int    shortestSpan() const;
    int    longestSpan() const;

private:
    unsigned int        _max;
    std::vector<int>    _numbers;
};



#endif */