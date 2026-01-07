#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include "bureaucrat.hpp"
#include "Aform.hpp"

class Bureaucrat;

class RRF: public AForm
{
	private:
		std::string _target;
		bool _robotomy;
		virtual void _performAction() const;
	
	public:
		RRF();
		RRF(const std::string target);
		RRF(const RRF&);
		RRF& operator=(const RRF&);
		~RRF();

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
