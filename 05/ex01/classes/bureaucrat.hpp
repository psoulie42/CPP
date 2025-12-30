#pragma once

#include <iostream>
#include <string>
#include <exception>

#define LOWEST_GRADE 150
#define HIGHEST_GRADE 1

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		const std::string getName() const;
		int getGrade() const;

		void gradeUp();
		void gradeDown();

		Bureaucrat();
		Bureaucrat(const std::string& name);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat&);
		Bureaucrat& operator=(const Bureaucrat&);
		~Bureaucrat();

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

std::ostream& operator<<(std::ostream&, Bureaucrat&);
