#include "Span.hpp"

// ------------- SPAN MEMBER FUNCTIONS -------------

void Span::addNumber(int number)
{
	if (_data.size() <= _n)
		throw ContainerFullException();

	_data.push_back(number);
}

unsigned int Span::longestSpan()
{
	if (_data.size() < 2)
		throw NotEnoughNumbersException();


	int lil;
	int big;

	for (int i = 0; i < _data.size(); i++)
	{
		if (_data[i] < lil)
			lil = _data[i];
		if (_data[i] > big)
			big = _data[i];
	}

	return (big - lil);
}

unsigned int Span::shortestSpan()
{
	if (_data.size() < 2)
		throw NotEnoughNumbersException();
	
	vector<int> sorted = _data;
	std::sort(sorted.begin(), sorted.end());

	unsigned int smol = std::numeric_limits<unsigned int>::max();
	for (int i = 0; i < sorted.size() - 1; i++)
	{
		if (smol > sorted[i + 1] - sorted[i])
			smol = sorted[i + 1] - sorted[i];
	}

	return (smol);
}

// -------------- EXCEPTIONS -------------

const char* Span::NotEnoughNumbersException::what() const throw()
{
	return ("There are not enough numbers to return a span!");
}

const char* Span::ContainerFullException::what() const throw()
{
	return ("Can't add more numbers: container is already full!");
}

// ------------- CONSTRUCTORS & DESTRUCTORS -------------

Span::Span(): _data(0), _n(0) {}

Span::Span(unsigned int n): _n(n) {}

Span::Span(const Span& b)
{
	_n = b._n;
	_data = b._data;
}

Span& Span::operator=(const Span& r)
{
	if (this == &r)
		return *this;

	_n = r._n;
	_data = r._data;
	return *this;
}

Span::~Span() {}
