#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <cstdlib>

#include "bureaucrat.hpp"
#include "Aform.hpp"

class Bureaucrat;

class SCF: public AForm
{
	private:
		std::string _target;
		virtual void _performAction() const;
	
	public:
		SCF();
		SCF(const std::string target);
		SCF(const SCF&);
		SCF& operator=(const SCF&);
		~SCF();

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
