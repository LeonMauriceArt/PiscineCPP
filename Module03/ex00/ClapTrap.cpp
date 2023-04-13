#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->Name = "NoName";
	this->AttackDamage = 0;
	this->EnergyPoints = 10;
	this->HitPoints = 10;
	std::cout << "Claptrap with no name created." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->Name = name;
	this->AttackDamage = 0;
	this->EnergyPoints = 10;
	this->HitPoints = 10;
	std::cout << "Claptrap " << this->Name << " created." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap " << this->Name << " destroyed." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &c)
{
	this->AttackDamage = c.AttackDamage;
	this->EnergyPoints = c.EnergyPoints;
	this->HitPoints = c.HitPoints;
	this->Name = c.Name;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->HitPoints == 0)
	{
		std::cout << "Claptrap " << this->Name << " try to attack " << target << ", but is dead and can't do anything." << std::endl;
		return;
	}
	if (this->EnergyPoints > 0)
	{
		this->EnergyPoints--;
		std::cout << "Claptrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " !" << std::endl;
		return;
	}
	std::cout << "Claptrap " << this->Name << " doesn't have enough energy to attack !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HitPoints == 0)
	{
		std::cout << "Claptrap " << this->Name << " is already dead and can't take damage." << std::endl;
		return;
	}
	if (amount >= this->HitPoints)
	{
		amount = this->HitPoints;
		std::cout << "Claptrap " << this->Name << " take " << amount << " damage, it is FATAL!" << std::endl;
		this->HitPoints = 0;
		return;
	}
	this->HitPoints -= amount;
	std::cout << "Claptrap " << this->Name << " take " << amount << " damage !" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->HitPoints <= 0)
	{
		std::cout << "Claptrap " << this->Name << " try to repair himself, but is dead and can't do anything." << std::endl;
		return;
	}
	if (amount > 10)
		amount = 10;
	if (this->EnergyPoints > 0)
	{
		this->EnergyPoints--;
		if (this->HitPoints == 10)
		{
			std::cout << "Claptrap " << this->Name << " tries to repair himself but is already healthy !" << std::endl;
			return;
		}
		if (this->HitPoints + amount <= 10)
			this->HitPoints += amount;
		else if (this->HitPoints + amount > 10)
		{
			amount = 10 - this->HitPoints;
			this->HitPoints = 10;
		}
		std::cout << "Claptrap " << this->Name << " has repaired himself " << amount << " points !" << std::endl;
		return;
	}
	std::cout << "Claptrap " << this->Name << " doesn't have enough energy to repair !" << std::endl;
}
