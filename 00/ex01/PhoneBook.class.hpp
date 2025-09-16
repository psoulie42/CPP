#ifndef PHONEBOOK_CLASS
# define PHONEBOOK_CLASS
# include "Contact.class.hpp"

# define MAX_CONTACTS 8

class PhoneBook
{
	private:
		Contact	_contacts[MAX_CONTACTS];

	public:
		int		addContact(int index);
		int		searchContact(int index);
		void	displayPrompt(void);
		void	displayContact(int index);
		void	displaySearchPrompt(int index);
		void	displayLine(int index);
		
		PhoneBook(void);
		~PhoneBook(void);
};

#endif
