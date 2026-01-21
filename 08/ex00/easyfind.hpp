#pragma once

#include <iostream>
#include <limits>
#include <iterator>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int ndl);

#include "easyfind.tpp"
