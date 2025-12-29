#include "classScavTrap.hpp"

// ------------- MEMBER FUNCTIONS -------------

void	ScavTrap::guardGate()
{
	this->_gateKeeping = true;
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

// CONSTRUCTORS & DESTRUCTOR & ASSIGNMENT OPERATOR OVERLOAD

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_gateKeeping = false;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << name << " created" << std::endl;
}

ScavTrap::ScavTrap(): ClapTrap("Johnny")
{
	this->_gateKeeping = false;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "Default ScavTrap created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& b): ClapTrap(b)
{
	this->_gateKeeping = b._gateKeeping;
	this->_energyPoints = b._energyPoints;
	this->_attackDamage = b._attackDamage;
	std::cout << "ScavTrap " << _name << " created" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& r)
{
	if (this == &r)
		return *this;

	this->_name = r._name;
	this->_hitPoints = r._hitPoints;
	this->_gateKeeping = r._gateKeeping;
	this->_energyPoints = r._energyPoints;
	this->_attackDamage = r._attackDamage;
	std::cout << "ScavTrap " <<  r._name << " assigned to new ScavTrap" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " destroyed" << std::endl;
}
