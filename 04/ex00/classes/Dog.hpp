#ifndef DOG_CLASS
# define DOG_CLASS

# include <iostream>
# include <string>
# include "Animal.hpp"

class Dog: public Animal
{
	public:
		void makeSound() const;

		Dog();
		Dog(const Dog&);
		Dog operator=(const Dog&);
		~Dog();
};

#endif