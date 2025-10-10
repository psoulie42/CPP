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

FragTrap::FragTrap(std::string name): ClapTrap(name), _ownEnergyPoints(100), _ownAttackDamage(30)
{
	this->_energyPoints = this->_ownEnergyPoints;
	this->_attackDamage = this->_ownAttackDamage;
	std::cout << "FragTrap " << name << " created" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " destroyed" << std::endl;
}
