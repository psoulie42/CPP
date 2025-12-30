#include "bureaucrat.hpp"

// ------------- BUREAUCRAT MEMBER FUNCTIONS ------------

const std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::gradeUp()
{
	if (_grade == HIGHEST_GRADE)
		throw GradeTooHighException();
	else
		_grade--;
}

void Bureaucrat::gradeDown()
{
	if (_grade == LOWEST_GRADE)
		throw GradeTooLowException();
	else
		_grade++;
}

// ------------- EXCEPTIONS -------------

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade too Low!");
}

// ------------- CONSTRUCTORS & DESTRUCTORS -------------

Bureaucrat::Bureaucrat(): _name("default"), _grade(LOWEST_GRADE)
{
	std::cout << "Bureaucrat " << _name << " successfully created with rank " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name): _name(name), _grade(LOWEST_GRADE)
{
	std::cout << "Bureaucrat " << _name << " successfully created with rank " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name)
{
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
	else
		_grade = grade;

	std::cout << "Bureaucrat " << _name << " successfully created with rank " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b): _name(b._name), _grade(b._grade)
{
	std::cout << "Bureaucrat " << _name << " successfully copied with rank " << _grade << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << " was fired." << std::endl;
}

// -------------- OPERATOR OVERLOADS -------------

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& r)
{
	if (this != &r)
		_grade = r._grade;
	return *this;
}

std::ostream& operator<<(std::ostream &os, Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return os;
}
