#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		int _signGrade;
		int _execGrade;
		virtual void _performAction() const = 0;
	
	public:
		const std::string getName() const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		
		void beSigned(Bureaucrat&);
		void execute(const Bureaucrat&) const;

		AForm();
		AForm(const std::string name, int signGrade, int execGrade);
		AForm(const AForm&);
		AForm& operator=(const AForm&);
		virtual ~AForm();

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

		class FormNotSignedException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, AForm& f);
