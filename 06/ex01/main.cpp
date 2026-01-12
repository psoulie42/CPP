#include "serialiser.hpp"

int main()
{
	Data data;
	Data* dataPtr;
	Data* dataPtr2;
	uintptr_t ptr;

	data.val = 42;
	dataPtr = &data;
	std::cout << "First data pointer: " << dataPtr << std::endl;

	ptr = Serialiser::serialise(dataPtr);
	std::cout << "After serialisation into uintptr_t: " << ptr << std::endl;

	dataPtr2 = Serialiser::deserialise(ptr);
	std::cout << "After deserialisation into new data ptr: " << dataPtr2 << std::endl
		<< "The first and last pointers should share the same value." << std::endl;

	return 0;
}
