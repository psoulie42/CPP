#ifndef DOG_CLASS
# define DOG_CLASS

# include <iostream>
# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal
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