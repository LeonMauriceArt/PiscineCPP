#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->_name = "No_name";
	this->_attackDamage = 30;
	this->_energyPoints = 100;
	this->_hitPoints = 100;
	this->_maxHitpoints = 100;
	std::cout << "FragTrap with no name created." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "Fragtrap named " << this->_name << " deleted." << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->_name = name;
	this->_attackDamage = 30;
	this->_energyPoints = 100;
	this->_hitPoints = 100;
	this->_maxHitpoints = 100;
	std::cout << "Fragtrap " << this->_name << " created." << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "Fragtrap " << this->_name << " try to attack " << target << ", but is dead and can't do anything." << std::endl;
		return;
	}
	if (this->_energyPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "Fragtrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " !" << std::endl;
		return;
	}
	std::cout << "Fragtrap " << this->_name << " doesn't have enough energy to attack !" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "Fragtrap " << this->_name << " is dead and can't highfive anymore." << std::endl;
		return;
	}
	std::cout << "Fragtrap " << this->_name << " asks for highfives !" << std::endl;
}
