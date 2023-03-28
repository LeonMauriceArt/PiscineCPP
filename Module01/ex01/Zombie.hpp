#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
    std::string name;

public:
    void announce(void) const;
    void setName(std::string str);
    Zombie(std::string str);
    Zombie(void);
    ~Zombie(void);
};

Zombie *zombieHorde(int N, std::string name);

#endif