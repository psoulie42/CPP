#include <bureaucrat.hpp>
#include <form.hpp>
#include <iostream>
#include <string>
#include <exception>

int main()
{
	Bureaucrat boss("Boss", 1);
	Bureaucrat joe("joe");
	
	Form f1("random Bullshit", 1, 1);

	std::cout << "JOE TRIES SIGNING FORM: ";
	joe.signForm(f1);
	std::cout << "BOSS DOES IT THEMSELVES: ";
	boss.signForm(f1);
	return (0);
}
