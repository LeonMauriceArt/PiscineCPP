#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scav("Vladimir");
	scav.takeDamage(99);
	scav.attack("Rusky");
	scav.takeDamage(12);
	return (0);
}