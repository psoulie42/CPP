#include "classes.h"
#include "wrongClasses.h"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;
	std::cout << std::endl;

	WrongAnimal *d = new WrongDog();
	std::cout << std::endl;

	std::cout << d->getType() << " " << std::endl;
	d->makeSound();
	std::cout << std::endl;

	delete d;
	return 0;
}
