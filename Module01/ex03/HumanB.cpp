#include "HumanB.hpp"

void HumanB::attack(void)
{
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

HumanB::HumanB(std::string name): name(name), weapon(NULL)
{
    std::cout << "HumanB " << name << " created with no weapon." << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << "HumanB " << this->name << " deleted." << std::endl;
}