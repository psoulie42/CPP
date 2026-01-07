#include "intern.hpp"

// ------------- INTERN MEMBER FUNCTIONS -------------

AForm *Intern::makeForm(std::string form, std::string target)
{
	std::string s[3] = {"PPF", "RRF", "SCF"};
	int	i = 0;

	while (i < 4 && s[i].compare(form) != 0)
		i++;
	switch(i)
	{
		case 0:
			std::cout << "New Presidential Pardon Form created by Intern" << std::endl;
			return new PPF(target);
			break;
		case 1:
			std::cout << "New Robotomy Request Form created by Intern" << std::endl;
			return new RRF(target);
			break;
		case 2:
			std::cout << "New Shrubbery Creation Form created by Intern" << std::endl;
			return new SCF(target);
			break;

		default:
			throw NoSuchFormException();
			break;
	};
}

const char *Intern::NoSuchFormException::what() const throw()
{
	return ("There exists no such form!");
}

// ------------ CONSTRUCTORS & DESTRUCTORS -------------

Intern::Intern() {}

Intern::Intern(const Intern& b)
{
	(void)b;
}

Intern& Intern::operator=(const Intern& r)
{
	(void)r;
	return *this;
}

Intern::~Intern() {};
