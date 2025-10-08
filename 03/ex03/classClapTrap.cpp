#include "classClapTrap.hpp"

// ------------- MEMBER FUNCTIONS -------------

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0) {
		std::cout << this->_name << " is exhausted and doesn't want to attack. Try again tomorrow." << std::endl;
		return; }
	if (this->_hitPoints <= 0) {
		std::cout << this->_name << " is dead. Maybe if you ask kindly it'll come back?" << std::endl;
		return; }
	std::cout << this->_name << " attacks " << target
		<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0) {
		std::cout << this->_name << " is already dead. Why would you do this to them?" << std::endl;
		return; }
	std::cout << this->_name << " has taken " << amount << " damage. See what you've done? Are you happy now??" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0) {
		std::cout << this->_name << " is exhausted and will not repair itself. Try again tomorrow." << std::endl;
		return; }
	if (this->_hitPoints <= 0) {
		std::cout << this->_name << " is dead. Maybe if you ask kindly it'll come back?" << std::endl;
		return; }
	std::cout<< this->_name << " has repaired itself, and has regained "
		<< amount << " health points." << std::endl;
	this->_energyPoints--;
}

std::string	ClapTrap::getName()
{
	return this->_name;
}

int	ClapTrap::getHitPoints()
{
	return this->_hitPoints;
}

int ClapTrap::getEnergyPoints()
{
	return this->_energyPoints;
}

int ClapTrap::getAttackDamage()
{
	return this->_attackDamage;
}

// ------------- CONSTRUCTOR & DESTRUCTOR -------------

ClapTrap::ClapTrap(std::string name): 
	_name(name), _hitPoints(100), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::~ClapTrap() 
{
	std::cout << "ClapTrap " << this->_name << " destroyed" << std::endl;
}
