#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
    private:
       std::string type;
    public:
        void setType(std::string str); 
        const std::string& getType(void);
        Weapon(std::string type);
        ~Weapon(void);
};

#endif