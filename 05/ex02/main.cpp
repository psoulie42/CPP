#include "bureaucrat.hpp"
#include "Aform.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <string>
#include <exception>
#include <ctime>

int main()
{
	srand(time(0)); // setting the seed for rand(), needed for Robotomy Requests

	Bureaucrat boss("Boss", 1);
	Bureaucrat joe("joe", 145);
	Bureaucrat mng("manager", 10);

	PPF ppf("Your dog");
	RRF rrf("Blastus");
	SCF scf("home");

	std::cout << "JOE TRIES EXECUTING FORM: ";
	joe.executeForm(ppf);
	std::cout << std::endl;

	std::cout << "MANAGER TRIES SIGNING FORM: ";
	mng.signForm(ppf);
	std::cout << std::endl;

	std::cout << "MANAGER TRIES EXECUTING FORM: ";
	mng.executeForm(ppf);
	std::cout << std::endl;

	std::cout << "BOSS DOES IT THEMSELVES: ";
	boss.executeForm(ppf);
	std::cout << std::endl;

	std::cout << "WE GOT NEW PAPERWORK. MANAGER WILL HANDLE IT: ";
	mng.signForm(rrf);
	mng.executeForm(rrf);
	std::cout << std::endl;

	std::cout << "PROMOTING JOE SO HE CAN ACTUALLY DO STUFF..." << std::endl;
	while (joe.getGrade() > 137)
		joe.gradeUp();

	std::cout << "GETTING JOE TO DO STUFF: ";
	joe.signForm(scf);
	joe.executeForm(scf);
	std::cout << "WELL DONE JOE! *CROWD APPLAUSE*" << std::endl;

	return (0);
}
