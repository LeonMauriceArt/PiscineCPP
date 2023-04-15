#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	FragTrap Keke("Keke");
	for (int i = 0; i < 102; i++)
		Keke.attack("someone");
	Keke.highFivesGuys();
	Keke.takeDamage(99);
	Keke.highFivesGuys();
	Keke.takeDamage(2);
	Keke.highFivesGuys();
	return (0);
}