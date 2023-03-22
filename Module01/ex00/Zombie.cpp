#include "Zombie.hpp"

void Zombie::announce() const
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string str)
{
    this->name = str;
    std::cout << "Zombie named " << this->name << " created." << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie named " << this->name << " deleted." << std::endl;
}