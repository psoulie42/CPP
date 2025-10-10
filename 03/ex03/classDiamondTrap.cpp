#include "classDiamondTrap.hpp"

// ------------- FLAVOUR FUNCTIONS, PAY NO MIND -------------

int processAnswer()
{
	std::string answer;

	std::cout << "So, will you come with me?" << RESET << " [y/n] ";
	std::cin >> answer;
	std::cin.ignore();
	if (!answer.compare("y") || !answer.compare("Y") || !answer.compare("yes") || !answer.compare("YES"))
		return 0;
	else if (!answer.compare("n") || !answer.compare("N") || !answer.compare("no") || !answer.compare("NO"))
		return 1;
	else
	{
		std::cout << CYAN << BOLD
		<< "My question was clear, short one, and I expect a clear answer from you." << std::endl;
		return processAnswer();
	}
}

int	plotPoint()
{
	int answer;
	std::string fodder;

	answer = processAnswer();
	if (answer == 1)
	{
		std::cout << CYAN << BOLD << "Oh... I see. Fine then, I will go alone. " << std::endl
			<< "I wish you the best, short one, and I hope we will meet again after this world has become a better place..."
			<< std::endl << "However slim that hope may be." << RESET;
			std::cin.get();
		return 1;
	}
	else
	{
		std::cout << CYAN << BOLD << "Great! I had long given up hope for a partner in this reckless endeavour."
			<< std::endl;
		return 0;
	}
}

// ------------- MEMBER FUNCTIONS ------------

void	DiamondTrap::whoAmI()
{
	std::cout << this->_name << ":"  << CYAN << BOLD
		<< " Hello, short one. I am a DiamondTrap, and my name is " << this->_name << "."
		<< std::endl << "However, I shall always remember where I came from. " << ClapTrap::_name
		<< " is what they used to call me." << std::endl
		<< "I will now venture deeper in the mist, to cut down the evil that plagues this land at its source."
		<< std::endl;
}

void	DiamondTrap::storyTelling()
{
	std::string name;
	std::string fodder;
	
	if (plotPoint() == 1)
		return ;
	std::cout << "One last thing before we go! Tell me short one, what is your name?" << std::endl;
	std::cout << RESET << "Enter your name: ";
	std::cin >> name;
	std::cin.ignore();
	std::cout << CYAN << BOLD << name << ", is that it? Well, thank you for joining me on such a fateful day, " << name
		<< ". " << std::endl
		<< "Now then, let us proceed, and may The One Who Waits be merciful.";
	std::cin.ignore();
	std::cout << std::endl << "While we are on the way, let me show you what I can do." << std::endl;
	this->status();
	std::cout << CYAN << BOLD << "Not bad huh?";
	std::cin.ignore();
	std::cout << std::endl << "!!! Shhhhh... This is it!! The source of the mist... Are you ready?" << std::endl;
	std::cout << RESET << "Press ENTER to proceed...";
	std::cin.ignore();
	std::cout << std::endl;
	ClapTrap *c = new ClapTrap("the lonely ClapTrap");
	std::cout << CYAN << BOLD << "It's just a SINGLE ClapTrap??" << std::endl
		<< "You're telling me I've waited this long, trained this hard for THIS??";
	std::cin.ignore(); 
	std::cout << std::endl << "I'm sorry " << name 
		<< ", it seems like I greatly overestimated the challenge ahead." << std::endl
		<< "Let me take care of this.";
	std::cin.ignore();
	std::cout << RESET;
	std::cout << std::endl;
	this->attack(c->getName());
	delete c;
	std::cin.ignore();
	std::cout << CYAN << BOLD << "Well, thank you for helping me save the world " << name << "!" << std::endl
		<< "Even though the fight itself was... underwhelming, to say the least. " << std::endl
		<< "Goodbye, and may we meet again my friend!" << RESET << std::endl;
	std::cin.ignore();
	return ;
}

void	DiamondTrap::status()
{
	std::cout << RESET << this->_name << " status: HP: " << this->_hitPoints << " EP: " << this->_energyPoints
		<< " DMG: " << this->_attackDamage << std::endl;
}

// ------------- CONSTRUCTOR & DESTRUCTOR -------------

DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	this->_energyPoints = ScavTrap::_ownEnergyPoints;
	this->_attackDamage = FragTrap::_ownAttackDamage;
	std::cout << "DiamondTrap " << name << " created" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << this->_name << " left" << std::endl;
}
