#include "Weapon.hpp"

void Weapon::setType(std::string str)
{
	if (str.empty())
	{
		this->type = "ghost weapon";
		return;
	}
    this->type = str;
}

const std::string& Weapon::getType(void)
{
    return (this->type);
}

Weapon::Weapon(std::string type)
{
	if (type.empty())
	{
		this->type = "ghost weapon";
		return;
	}
	this->type = type;
}

Weapon::~Weapon(void)
{
}