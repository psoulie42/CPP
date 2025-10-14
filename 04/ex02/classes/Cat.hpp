#ifndef CAT_CLASS
# define CAT_CLASS

# include <iostream>
# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal
{
	private:
		Brain* brain;
	public:
		void makeSound() const;
		Brain* getBrain();

		Cat();
		Cat(const Cat&);
		Cat operator=(const Cat&);
		~Cat();
};

#endif