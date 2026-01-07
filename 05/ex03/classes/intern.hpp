#pragma once

#include <stdio.h>
#include <string>

#include "Aform.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		AForm *makeForm(std::string form, std::string target);

		Intern();
		Intern(const Intern&);
		Intern& operator=(const Intern&);
		~Intern();

		class NoSuchFormException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
