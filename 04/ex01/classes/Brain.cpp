#include "Brain.hpp"

// ------------- MEMBER FUNCTIONS -------------

void Brain::setIdeas(int i, std::string s)
{
	this->ideas[i] = s;
}

std::string Brain::getIdea(int i)
{
	return this->ideas[i];
}

Brain::Brain()
{
	std::cout << "Brain created" << std::endl;
}

Brain::Brain(const Brain& brain)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
	std::cout << "Brain copied" << std::endl;
}

Brain Brain::operator=(const Brain& brain)
{
	if (this != &brain)
		for (int i = 0; i < 100; i++)
			this->ideas[i] = brain.ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain Destroyed" << std::endl;
}
