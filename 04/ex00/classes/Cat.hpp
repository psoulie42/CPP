#ifndef CAT_CLASS
# define CAT_CLASS

# include <iostream>
# include <string>
# include "Animal.hpp"

class Cat: public Animal
{
	public:
		void makeSound() const;

		Cat();
		Cat(const Cat&);
		Cat operator=(const Cat&);
		~Cat();
};

#endif