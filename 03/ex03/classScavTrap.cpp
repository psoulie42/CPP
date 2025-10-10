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
	this->_energyPoints--;
}

void	ScavTrap::sstatus()
{
	std::cout << this->_name << " status: HP: " << this->_hitPoints << " EP: " << this->_energyPoints
		<< " DMG: " << this->_attackDamage << std::endl;
}

// CONSTRUCTOR & DESTRUCTOR

ScavTrap::ScavTrap(std::string name): ClapTrap(name), _ownEnergyPoints(50), _ownAttackDamage(20)
{
	this->_energyPoints = this->_ownEnergyPoints;
	this->_attackDamage = this->_ownAttackDamage;
	std::cout << "ScavTrap " << name << " created" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " destroyed" << std::endl;
}
