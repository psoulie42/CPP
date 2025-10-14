#ifndef WRONG_DOG_CLASS
# define WRONG_DOG_CLASS

# include <iostream>
# include <string>
# include "WrongAnimal.hpp"

class WrongDog: public WrongAnimal
{
	public:
		void makeSound() const;

		WrongDog();
		WrongDog(const WrongDog&);
		WrongDog operator=(const WrongDog&);
		~WrongDog();
};

#endif