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

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << "." << std::endl;
	}
	catch (const AForm::GradeTooLowException& e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& f) const
{
	try
	{
		f.execute(*this);
		std::cout << "Form " << f.getName() << " executed by " << _name << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't execute form " << f.getName() << ": ";
		std::cerr << e.what() << std::endl;
	}
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

Bureaucrat::Bureaucrat(): _name("default"), _grade(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(const std::string& name): _name(name), _grade(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name)
{
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b): _name(b._name), _grade(b._grade) {}

Bureaucrat::~Bureaucrat() {}

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
