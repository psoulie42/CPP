#pragma once

#include <iostream>

#include "../data.h"

class Serialiser
{
	public:
		static uintptr_t serialise(Data* ptr);
		static Data* deserialise(uintptr_t raw);
};
