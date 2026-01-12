#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate()
{
	int type = rand() % 3;

	switch (type)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;

		default:
			return NULL;
	}
}

void identify(Base* p)
{
	if (p == NULL)
		std::cout << "wtf? please try compiling again." << std::endl;
	else if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	if (dynamic_cast<A*>(&(p)))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(&(p)))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(&(p)))
		std::cout << "C" << std::endl;
}

int main()
{
	srand(time(0)); // setting random seed for generate

	Base* p = generate();

	std::cout << "Pointer identification: ";
	identify(p);
	std::cout << std::endl;

	std::cout << "Reference identification: ";
	identify(&(*p));
	std::cout << std::endl;

	return (0);
}
