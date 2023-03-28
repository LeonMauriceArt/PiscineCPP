#include "Zombie.hpp"

void Zombie::announce() const
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string str)
{
    this->name = str;
}

Zombie::Zombie(std::string str)
{
    this->name = str;
}

Zombie::Zombie(void)
{
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie named " << this->name << " deleted." << std::endl;
}