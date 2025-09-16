#include "PhoneBook.class.hpp"

int main()
{
	PhoneBook	pb;
	std::string	input;
	int			index = 0;

	std::cout << "Welcome to your super awesome phonebook!!!!!!!" << std::endl;
	while (true)
	{
		pb.displayPrompt();
		std::cin >> input;
		if (input == "ADD")
		{
			if (pb.addContact(index))
				index++;
		}
		else if (input == "SEARCH")
			pb.searchContact(index);
		else if (input == "EXIT")
			break ;
	}
	return (0);
}
