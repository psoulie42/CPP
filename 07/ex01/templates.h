#pragma once

template <typename T>
void iter(T* addr, const int len, void(* func)(T& target))
{
	for (int i = 0; i < len; i++)
		func(addr[i]);
}

template <typename T>
void plusOne(T& target)
{
	target++;
}

template <typename T>
void print(T& target)
{
	std::cout << target;
}
