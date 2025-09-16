#include "PhoneBook.class.hpp"

void	PhoneBook::displayPrompt(void)
{
	std::cout << std::endl 
		<< "Do you wish to ADD contact, SEARCH for existing contact or EXIT phonebook?"
		<< std::endl;
}

int	PhoneBook::addContact(int index)
{
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;


	std::cout << "Enter first name: ";
	std::cin >> firstName;
	std::cout << "Enter last name: ";
	std::cin >> lastName;
	std::cout << "Enter nickname: ";
	std::cin >> nickname;
	std::cout << "Enter phone number: ";
	std::cin >> phoneNumber;
	std::cout << "Enter darkest secret: ";
	std::cin >> darkestSecret;
	

	if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty()) {
		std::cout << "Contact not added." << std::endl << "Contact can't have empty field." << std::endl;
		return 0; }


	this->_contacts[index % MAX_CONTACTS].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	std::cout << "Contact added successfully!" << std::endl;
	return 1;
}

void	displayString(std::string str)
{
	for (int i = 0; i < (int)(10 - str.size()); i++)
		std::cout << " ";
	if (str.size() <= 10)
		std::cout << str << "|";
	if (str.size() > 10)
	{
		for (unsigned int i = 0; i < 9 && i < str.size(); i++)
			std::cout << str[i];
		std::cout << ".|";
	}
}

void	PhoneBook::displayLine(int index)
{
	std::string	firstName;
	std::string	lastName;
	std::string nickname;

	firstName = this->_contacts[index].getFirstName();
	lastName = this->_contacts[index].getLastName();
	nickname = this->_contacts[index].getNickname();

	if (index == -1)
		std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	else if (index > 8)
		std::cout << " -------------------------------------------" << std::endl;
	else
	{
		std::cout << "|         " << index << "|";
		displayString(firstName);
		displayString(lastName);
		displayString(nickname);
		std::cout << std::endl;
	}
}

void	PhoneBook::displaySearchPrompt(int index)
{
	displayLine(9);
	displayLine(-1);
	displayLine(9);
	for (int i = 0; i < index && i < 8; i++)
		displayLine(i);
	displayLine(9);
	std::cout << "Enter index for details: ";
}

void	PhoneBook::displayContact(int index)
{
	Contact contact = _contacts[index];

	std::cout << "Here is contact " << index << "'s information: " << std::endl;
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
}

int	PhoneBook::searchContact(int index)
{
	int	answer;

	if (index == 0) {
		std::cout << "No contact has been added yet." << std::endl;
		return 1;}
	displaySearchPrompt(index);
	std::cin >> answer;
	if (std::cin.fail() || !index || index <= answer || answer < 0 || answer > 7) {
		std::cout << "Invalid index" << std::endl;
		answer = -1;
		std::cin.clear();
		std::cin.ignore();
		return (1);}
	else {
		displayContact(answer);
		return (0);}
}

PhoneBook::PhoneBook(void)
{
	for (int i = 0; i < MAX_CONTACTS; i++)
		_contacts[i] = Contact();
}

PhoneBook::~PhoneBook(void) {}
