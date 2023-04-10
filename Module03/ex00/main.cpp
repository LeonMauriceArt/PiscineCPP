#include "ClapTrap.hpp"

int main(void)
{

	std::cout << "----------Joe and John tests---------" << std::endl;
	ClapTrap Joe("Joe");
	ClapTrap John;
	Joe.attack("someone");
	Joe.takeDamage(15);
	Joe.beRepaired(3);
	Joe.takeDamage(6);
	John = Joe;
	John.attack("someone");
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "--------------Bill damage / repair tests-------------" << std::endl;
	ClapTrap Bill("Bill");
	Bill.takeDamage(8);
	Bill.beRepaired(90);
	Bill.takeDamage(11);
	Bill.attack("someone");
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "--------------Sarah energy tests-------------" << std::endl;
	ClapTrap Sarah("Sarah");
	Sarah.beRepaired(1);
	Sarah.beRepaired(3);
	Sarah.beRepaired(1);
	Sarah.beRepaired(55);
	Sarah.beRepaired(10);
	Sarah.beRepaired(1);
	Sarah.beRepaired(4);
	Sarah.beRepaired(1);
	Sarah.beRepaired(1);
	Sarah.beRepaired(1);
	Sarah.beRepaired(101);
	Sarah.attack("someone");
	Sarah.takeDamage(30);
	Sarah.beRepaired(101);
	Sarah.attack("someone");
	Sarah.takeDamage(30);
	return (0);
}