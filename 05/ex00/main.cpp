#include <bureaucrat.hpp>
#include <iostream>
#include <string>
#include <exception>

int main()
{
	std::cout << "CREATING BUREAUCRATS:" << std::endl;

	try
	{
		std::cout << "Try with rank -1: ";
		Bureaucrat boss("Boss", -1);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}


	try
	{
		std::cout << "Try with rank 1000: ";
		Bureaucrat boss("joe", 1000);
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "CREATING ACTUAL BUREAUCRATS:" << std::endl;
	Bureaucrat boss("Boss", 1);
	Bureaucrat joe("joe");
	std::cout << std::endl;

	std::cout << "TESTING EXCEPTIONS:" << std::endl;

	try
	{
		std::cout << "Try promoting boss: ";
		boss.gradeUp();
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Try demoting joe: ";
		joe.gradeDown();
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "GIVING JOE A PROMOTION:" << std::endl,

	std::cout << joe;
	joe.gradeUp();
	std::cout << joe;
	std::cout << "CONGRATS JOE! *CROWD APPLAUSE*" << std::endl;

	return (0);
}
