#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scav("Vladimir");
	ScavTrap clap(scav);
	scav.takeDamage(99);
	scav.attack("Rusky");
	scav.takeDamage(12);
	scav.attack("Pootine");
	return (0);
}