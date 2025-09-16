#include "Contact.class.hpp"

std::string Contact::getFirstName(void)
{
	return _firstName;
}

std::string Contact::getLastName(void)
{
	return _lastName;
}

std::string Contact::getNickname(void)
{
	return _nickname;
}

std::string Contact::getPhoneNumber(void)
{
	return _phoneNumber;
}

std::string Contact::getDarkestSecret(void)
{
	return _darkestSecret;
}

void	Contact::setContact(std::string firstName, std::string lastName, std::string nickname,
		std::string phoneNumber, std::string darkestSecret)
{
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickname;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;
}

Contact::Contact() {}

Contact::~Contact(void) {}
