#include "ClapTrap.hpp"

class ScavTrap: private ClapTrap
{
	public:
		ScavTrap();
		~ScavTrap();
		void guardGate();
}