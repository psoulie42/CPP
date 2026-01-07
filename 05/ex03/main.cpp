#include "bureaucrat.hpp"
#include "Aform.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "intern.hpp"

#include <iostream>
#include <string>
#include <exception>
#include <ctime>

int main()
{
	srand(time(0)); // setting the seed for rand(), needed for Robotomy Requests

	Bureaucrat boss("Boss", 1);
	Bureaucrat joe("joe", 137);
	Intern dude;
	AForm *form;

	std::cout << "That's not the one, dude!" << std::endl;
	try
	{
		form = dude.makeForm("test", "joe");
	}
	catch (const Intern::NoSuchFormException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Here try again, then go make some coffee!" << std::endl;
	try
	{
		form = dude.makeForm("SCF", "home");
	}
	catch(const Intern::NoSuchFormException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	joe.signForm(*form);
	joe.executeForm(*form);
	std::cout << "WELL DONE JOE! *CROWD APPLAUSE*" << std::endl;

	delete form;
	return (0);
}
