#include "form.hpp"

// ------------- FORM MEMBER FUNCTIONS ------------

const std::string Form::getName()
{
	return _name;
}

bool Form::isSigned()
{
	return _isSigned;
}

int Form::getSignGrade()
{
	return _signGrade;
}

int Form::getExecGrade()
{
	return _execGrade;
}

void Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > _signGrade)
		throw GradeTooLowException();
	else
		_isSigned = true;
}

// CONSTRUCTORS & DESTRUCTORS

Form::Form(): _name("default form"), _isSigned(false), _signGrade(LOWEST_GRADE), _execGrade(LOWEST_GRADE) {}

Form::Form(std::string name, int signGrade, int execGrade): _isSigned(false), _name(name)
{
	if (signGrade < HIGHEST_GRADE || execGrade < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (signGrade > LOWEST_GRADE || execGrade > LOWEST_GRADE)
		throw GradeTooLowException();
	else
	{
		_signGrade = signGrade;
		_execGrade = execGrade;
	}
}

Form::Form(const Form& b): _isSigned(false), _name(b._name),
	_signGrade(b._signGrade), _execGrade(b._execGrade) {}

Form::~Form() {}

// ------------- OPERATOR OVERLOADS -------------

Form& Form::operator=(const Form& r)
{
	if (this == &r)
		return *this;

	_isSigned = r._isSigned;
	_signGrade = r._signGrade;
	_execGrade = r._execGrade;
}

std::ostream& operator<<(std::ostream& os, Form& f)
{
	std::cout << "Form " << f.getName() << ", status: ";
	if (f.isSigned())
		std::cout << "signed." << std::endl;
	else
		std::cout << "unsigned." << std::endl;
	std::cout << "Minimum grade to sign: " << f.getSignGrade() << std::endl;
	std::cout << "Minimum grade to execute: " << f.getExecGrade() << std::endl;
}
