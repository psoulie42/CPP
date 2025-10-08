#include "classScavTrap.hpp"

// ------------- MEMBER FUNCTIONS -------------

void	ScavTrap::guardGate()
{
	std::cout << this->_name << " is guarding the gate, whatever that means." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0) {
		std::cout << this->_name << " is exhausted and doesn't want to attack. Try again tomorrow." << std::endl;
		return; }
	if (this->_hitPoints <= 0) {
		std::cout << this->_name << " is dead. Maybe if you ask kindly it'll come back?" << std::endl;
		return; }
	std::cout << this->_name << " DESTROYS " << target << ", dealing " << this->_attackDamage
		<< " points of damage." << std::endl;
}

// CONSTRUCTOR & DESTRUCTOR

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << name << " created" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " destroyed" << std::endl;
}
