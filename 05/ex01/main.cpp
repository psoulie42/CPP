#include <bureaucrat.hpp>
#include <form.hpp>
#include <iostream>
#include <string>
#include <exception>

int main()
{
	Bureaucrat boss("Boss", 1);
	Bureaucrat joe("joe", 149);
	
	Form f1("random Bullshit", 145, 1);

	std::cout << "JOE TRIES SIGNING FORM: ";
	joe.signForm(f1);

	std::cout << "BOSS DOES IT THEMSELVES: ";
	boss.signForm(f1);
	std::cout << std::endl;

	std::cout << "PROMOTING JOE UNTIL HE CAN ACTUALLY DO STUFF: ";
	while (joe.getGrade() > 145)
		joe.gradeUp();
	std::cout << joe;

	std::cout << "JOE TRIES AGAIN: ";
	joe.signForm(f1);
	std::cout << "Well done joe!! *CROWD APPLAUSE*" << std::endl;
	return (0);
}
