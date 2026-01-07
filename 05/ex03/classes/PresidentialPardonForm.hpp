#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "bureaucrat.hpp"
#include "Aform.hpp"

class Bureaucrat;

class PPF: public AForm
{
	private:
		std::string _target;
		virtual void _performAction() const;
	
	public:
		PPF();
		PPF(const std::string target);
		PPF(const PPF&);
		PPF& operator=(const PPF&);
		~PPF();

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
