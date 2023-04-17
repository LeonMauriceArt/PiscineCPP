#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:
		static const int _maxHitpoints = 100;
		bool _keepingGate;
	public:
		ScavTrap();
		ScavTrap(std::string name);
		void attack(const std::string &target);
		~ScavTrap();
		void guardGate(void);
};

#endif