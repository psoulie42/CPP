#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& container, int ndl)
{
	typename T::iterator it = std::find(container.begin(), container.end(), ndl);

	if (it == container.end())
		throw std::runtime_error("Value not found!");
	
	return it;
};
