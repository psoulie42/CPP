#ifndef ANIMAL_CLASS
# define ANIMAL_CLASS

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string type;
	
	public:
		virtual void makeSound() const;
		std::string getType() const;

		Animal();
		Animal(const Animal&);
		Animal operator=(const Animal&);
		virtual ~Animal();
};

#endif