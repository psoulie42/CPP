#pragma once

#include <iostream>
#include <limits>
#include <iterator>
#include <stdexcept>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int ndl);

template <typename T>
static void displayContainer(T& container);

#include "easyfind.tpp"
