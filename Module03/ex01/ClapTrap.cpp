#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->_name = "No_name";
	this->_attackDamage = 0;
	this->_energyPoints = 10;
	this->_hitPoints = 10;
	std::cout << "Claptrap with no name created." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_attackDamage = 0;
	this->_energyPoints = 10;
	this->_hitPoints = 10;
	std::cout << "Claptrap " << this->_name << " created." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap " << this->_name << " destroyed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &c)
{
	this->_name = c._name;
	this->_hitPoints = c._hitPoints;
	this->_energyPoints = c._energyPoints;
	this->_attackDamage = c._attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &c)
{
	this->_name = c._name;
	this->_hitPoints = c._hitPoints;
	this->_energyPoints = c._energyPoints;
	this->_attackDamage = c._attackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "Claptrap " << this->_name << " try to attack " << target << ", but is dead and can't do anything." << std::endl;
		return;
	}
	if (this->_energyPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "Claptrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " !" << std::endl;
		return;
	}
	std::cout << "Claptrap " << this->_name << " doesn't have enough energy to attack !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "Claptrap " << this->_name << " is already dead and can't take damage." << std::endl;
		return;
	}
	if (amount >= (unsigned int)this->_hitPoints)
	{
		amount = this->_hitPoints;
		std::cout << "Claptrap " << this->_name << " take " << amount << " damage, it is FATAL!" << std::endl;
		this->_hitPoints = 0;
		return;
	}
	this->_hitPoints -= amount;
	std::cout << "Claptrap " << this->_name << " take " << amount << " damage !" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "Claptrap " << this->_name << " try to repair himself, but is dead and can't do anything." << std::endl;
		return;
	}
	if (amount > this->_maxHitpoints)
		amount = this->_maxHitpoints;
	if (this->_energyPoints > 0)
	{
		this->_energyPoints--;
		if (this->_hitPoints == (int)this->_maxHitpoints)
		{
			std::cout << "Claptrap " << this->_name << " tries to repair himself but is already healthy !" << std::endl;
			return;
		}
		if (this->_hitPoints + amount <= this->_maxHitpoints)
			this->_hitPoints += amount;
		else if (this->_hitPoints + amount > this->_maxHitpoints)
		{
			amount = this->_maxHitpoints - this->_hitPoints;
			this->_hitPoints = this->_maxHitpoints;
		}
		std::cout << "Claptrap " << this->_name << " has repaired himself " << amount << " points !" << std::endl;
		return;
	}
	std::cout << "Claptrap " << this->_name << " doesn't have enough energy to repair !" << std::endl;
}
