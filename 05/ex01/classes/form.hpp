#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		int _signGrade;
		int _execGrade;
	
	public:
		const std::string getName();
		bool isSigned();
		int getSignGrade();
		int getExecGrade();
		
		void beSigned(Bureaucrat&);

		Form();
		Form(const std::string name, int signGrade, int execGrade);
		Form(const Form&);
		Form& operator=(const Form&);
		~Form();

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

std::ostream& operator<<(std::ostream& os, Form& f);
