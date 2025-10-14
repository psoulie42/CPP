#ifndef DOG_CLASS
# define DOG_CLASS

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain* brain;
	public:
		void makeSound() const;
		Brain* getBrain();

		Dog();
		Dog(const Dog&);
		Dog operator=(const Dog&);
		~Dog();
};

#endif