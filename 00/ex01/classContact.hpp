#ifndef CONTACT_CLASS
# define CONTACT_CLASS

# include <iostream>
# include <string>

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
	public:
		std::string	getFirstName(void);
		std::string getLastName(void);
		std::string getNickname(void);
		std::string getPhoneNumber(void);
		std::string getDarkestSecret(void);
		void	setContact(std::string firstName, std::string lastName, std::string nickname,
		std::string phoneNumber, std::string darkestSecret);

		Contact(void);
		~Contact(void);

};

#endif
