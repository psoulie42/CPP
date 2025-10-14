#ifndef AANIMAL_CLASS
# define AANIMAL_CLASS

# include <iostream>
# include <string>

class AAnimal
{
	protected:
		std::string type;
	
	public:
		virtual void makeSound() const = 0;
		std::string getType() const;

		AAnimal();
		AAnimal(const AAnimal&);
		// operator cant be used anymore
		virtual ~AAnimal();
};

#endif