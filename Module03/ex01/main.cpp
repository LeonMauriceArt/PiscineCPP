#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scav("Vladimir");
	ScavTrap clap(scav);
	scav.takeDamage(66);
	scav.takeDamage(10);
	for (int i = 0; i < 55; i++)
		scav.attack("Someone");
	scav.attack("Rusky");
	scav.guardGate();
	scav.guardGate();
	scav.takeDamage(-30);
	scav.attack("Pootine");
	return (0);
}