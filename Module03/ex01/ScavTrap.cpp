#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->Name = "Unknown";
	this->AttackDamage = 20;
	this->EnergyPoints = 50;
	this->HitPoints = 100;
	this->keepingGate = false;
	std::cout << "ScavTrap with no name created." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Scavtrap named " << this->Name << " deleted." << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->Name = name;
	this->AttackDamage = 20;
	this->EnergyPoints = 50;
	this->HitPoints = 100;
	this->keepingGate = false;
	std::cout << "Scavtrap " << this->Name << " created." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->HitPoints <= 0)
	{
		std::cout << "Scavtrap " << this->Name << " try to attack " << target << ", but is dead and can't do anything." << std::endl;
		return;
	}
	if (this->EnergyPoints > 0)
	{
		this->EnergyPoints--;
		std::cout << "Scavtrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " !" << std::endl;
		return;
	}
	std::cout << "Scavtrap " << this->Name << " doesn't have enough energy to attack !" << std::endl;
}

void ScavTrap::guardGate()
{
	if (this->keepingGate == true)
	{
		std::cout << "Scavtrap " << this->Name << " is already in Gate keeper mode." << std::endl;
		return;
	}
	this->keepingGate = true;
	std::cout << "Scavtrap " << this->Name << " has entered Gate keeper mode." << std::endl;
}

