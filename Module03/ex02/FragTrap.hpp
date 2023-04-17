#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	private :
		static const int _maxHitpoints = 100;
	public:
		FragTrap();
		FragTrap(std::string name);
		void attack(const std::string &target);
		~FragTrap();
		void highFivesGuys(void);
};

#endif