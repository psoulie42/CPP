#ifndef WRONG_ANIMAL_CLASS
# define WRONG_ANIMAL_CLASS

# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string type;
	
	public:
		void makeSound() const;
		std::string getType() const;

		WrongAnimal();
		WrongAnimal(const WrongAnimal&);
		WrongAnimal operator=(const WrongAnimal&);
		virtual ~WrongAnimal();
};

#endif