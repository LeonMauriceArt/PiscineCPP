#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->_name = "Unknown";
	this->_attackDamage = 20;
	this->_energyPoints = 50;
	this->_hitPoints = 100;
	this->_maxHitpoints = 100;
	this->_keepingGate = false;
	std::cout << "ScavTrap with no name created." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Scavtrap named " << this->_name << " deleted." << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->_name = name;
	this->_attackDamage = 20;
	this->_energyPoints = 50;
	this->_hitPoints = 100;
	this->_maxHitpoints = 100;
	this->_keepingGate = false;
	std::cout << "Scavtrap " << this->_name << " created." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "Scavtrap " << this->_name << " try to attack " << target << ", but is dead and can't do anything." << std::endl;
		return;
	}
	if (this->_energyPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "Scavtrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " !" << std::endl;
		return;
	}
	std::cout << "Scavtrap " << this->_name << " doesn't have enough energy to attack !" << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "Scavtrap " << this->_name << " is dead and can't keep anything." << std::endl;
		return;
	}
	if (this->_keepingGate == true)
	{
		std::cout << "Scavtrap " << this->_name << " is already in Gate keeper mode." << std::endl;
		return;
	}
	std::cout << "Scavtrap " << this->_name << " has entered Gate keeper mode." << std::endl;
}

