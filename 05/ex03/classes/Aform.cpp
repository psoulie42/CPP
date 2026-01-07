#include "Aform.hpp"

// ------------- AFORM MEMBER FUNCTIONS ------------

const std::string AForm::getName() const
{
	return _name;
}

bool AForm::isSigned() const
{
	return _isSigned;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecGrade() const
{
	return _execGrade;
}

void AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > _signGrade)
		throw GradeTooLowException();
	else
		_isSigned = true;
}

void AForm::execute(const Bureaucrat& b) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	else if (b.getGrade() > _execGrade)
		throw GradeTooLowException();
	
	_performAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade too Low!");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed!");
}

// CONSTRUCTORS & DESTRUCTORS

AForm::AForm(): _name("default Aform"), _isSigned(false), _signGrade(LOWEST_GRADE), _execGrade(LOWEST_GRADE) {}

AForm::AForm(std::string name, int signGrade, int execGrade):_name(name), _isSigned(false)
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

AForm::AForm(const AForm& b): _name(b._name), _isSigned(false),
	_signGrade(b._signGrade), _execGrade(b._execGrade) {}

AForm::~AForm() {}

// ------------- OPERATOR OVERLOADS -------------

AForm& AForm::operator=(const AForm& r)
{
	if (this == &r)
		return *this;

	_isSigned = r._isSigned;
	_signGrade = r._signGrade;
	_execGrade = r._execGrade;
	return *this;
}

std::ostream& operator<<(std::ostream& os, AForm& f)
{
	os << "Form " << f.getName() << ", status: ";
	if (f.isSigned())
		os << "signed." << std::endl;
	else
		os << "unsigned." << std::endl;
	os << "Minimum grade to sign: " << f.getSignGrade() << std::endl;
	os << "Minimum grade to execute: " << f.getExecGrade() << std::endl;
	return os;
}
