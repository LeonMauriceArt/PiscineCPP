#include "Weapon.hpp"

void Weapon::setType(std::string str)
{
    this->type = str;
}

const std::string& Weapon::getType(void)
{
    return (this->type);
}

Weapon::Weapon(std::string type)
{
    this->type = type;
}

Weapon::~Weapon(void)
{
}