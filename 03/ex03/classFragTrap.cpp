#include "classFragTrap.hpp"

// ------------- MEMBER FUNCTIONS -------------

void	FragTrap::highFivesGuys()
{
	std::cout << this->_name << ": Hey guys, high five!! ...come on! ...anyone?" << std::endl;
}

void	FragTrap::attack(std::string target)
{
	if (this->_energyPoints <= 0) {
		std::cout << this->_name << " is exhausted and doesn't want to attack. Try again tomorrow." << std::endl;
		return; }
	if (this->_hitPoints <= 0) {
		std::cout << this->_name << " is dead. Maybe if you ask kindly it'll come back?" << std::endl;
		return; }
	std::cout << this->_name << " OBLITERATES " << target << ", dealing " << this->_attackDamage
		<< " points of damage." << std::endl;
	this->_energyPoints--;
}

void	FragTrap::fstatus()
{
	std::cout << this->_name << " status: HP: " << this->_hitPoints << " EP: " << this->_energyPoints
		<< " DMG: " << this->_attackDamage << std::endl;
}

// ------------- CONSTRUCTOR & DESTRUCTOR -------------

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << name << " created" << std::endl;
}

FragTrap::FragTrap(): ClapTrap("Jimmy")
{
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "Default FragTrap created" << std::endl;
}

FragTrap::FragTrap(const FragTrap& b): ClapTrap(b)
{
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << _name << " created" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& r)
{
	if (this == &r)
		return *this;

	this->_energyPoints = r._energyPoints;
	this->_attackDamage = r._attackDamage;
	std::cout << "FragTrap " <<  r._name << " assigned to new FragTrap" << std::endl;

	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " destroyed" << std::endl;
}
