#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
    std::string name;
public:
    void announce(void) const;
    Zombie(/* args */);
    ~Zombie();
};

Zombie::Zombie(/* args */)
{
}

Zombie::~Zombie()
{
}

#endif