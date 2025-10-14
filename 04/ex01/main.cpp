#include "classes.h"
#include "Brain.hpp"
#include "wrongClasses.h"

int main()
{
	std::cout << "------------- TESTING LEAKS -------------" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;
	
	delete j;
	delete i;
	std::cout << std::endl;

	std::cout << "------------- TESTING DEPTH OF DOG COPIES -------------" << std::endl;
	Dog doggy;
	Dog doggo(doggy);
	std::cout << std::endl;

	std::cout << "doggy's brain is at " << doggy.getBrain() << std::endl;
	std::cout << "doggo's brain is at " << doggo.getBrain() << std::endl;
	(*doggy.getBrain()).setIdeas(0, "Chase the ball");
	std::cout << "Doggy go " << (*doggy.getBrain()).getIdea(0) << std::endl;
	(*doggo.getBrain()).setIdeas(0, "Got the zoomies");
	std::cout << "Doggo go " << (*doggo.getBrain()).getIdea(0) << std::endl;
	std::cout << "Doggy go " << (*doggy.getBrain()).getIdea(0) << std::endl;
	std::cout << std::endl;
	
	std::cout << "------------- SHOWING BAD EXAMPLE -------------" << std::endl;
	WrongDog badDoggy;
	WrongDog badDoggo(badDoggy);
	std::cout << std::endl;


	std::cout << "badDoggy's brain is at " << badDoggy.getBrain() << std::endl;
	std::cout << "badDoggo's brain is at " << badDoggo.getBrain() << std::endl;
	(*badDoggy.getBrain()).setIdeas(0, "Chase the ball");
	std::cout << "badDoggy go " << (*badDoggy.getBrain()).getIdea(0) << std::endl;
	(*badDoggo.getBrain()).setIdeas(0, "Got the zoomies");
	std::cout << "badDoggo go " << (*badDoggo.getBrain()).getIdea(0) << std::endl;
	std::cout << "badDoggy go " << (*badDoggy.getBrain()).getIdea(0) << std::endl;
	std::cout << std::endl;

	delete badDoggo.getBrain();
	return 0;
}
