#ifndef WRONG_DOG_CLASS
# define WRONG_DOG_CLASS

# include <iostream>
# include <string>
# include "WrongAnimal.hpp"
# include "Brain.hpp"

class WrongDog: public WrongAnimal
{
	private:
		Brain* brain;
	public:
		void makeSound() const;
		Brain* getBrain();

		WrongDog();
		WrongDog(const WrongDog&);
		WrongDog operator=(const WrongDog&);
		~WrongDog();
};

#endif