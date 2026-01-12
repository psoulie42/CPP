#include "serialiser.hpp"

uintptr_t Serialiser::serialise(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialiser::deserialise(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
