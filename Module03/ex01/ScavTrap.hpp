#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:
		bool keepingGate;
	public:
		ScavTrap();
		ScavTrap(std::string name);
		void attack(const std::string &target);
		~ScavTrap();
		void guardGate();
};

#endif