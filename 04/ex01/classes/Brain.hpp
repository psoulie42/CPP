#ifndef BRAIN_CLASS
# define BRAIN_CLASS

# include <iostream>
# include <ostream>

class Brain
{
	private:
		std::string ideas[100];
	public:
		void setIdeas(int index, std::string idea);
		std::string getIdea(int index);

		Brain();
		Brain(const Brain&);
		Brain operator=(const Brain&);
		~Brain();
};

#endif