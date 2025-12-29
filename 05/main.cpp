#include <bureaucrat.hpp>
#include <iostream>
#include <string>
#include <exception>

int main()
{
	Bureaucrat boss("Boss", 1);
	Bureaucrat joe("joe");

	std::cout << "TESTING EXCEPTIONS:" << std::endl;

	try
	{
		boss.gradeUp();
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
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

	return (0);
}
