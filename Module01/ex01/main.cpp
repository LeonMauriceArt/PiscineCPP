#include "Zombie.hpp"

int main(void)
{
    Zombie* horde = zombieHorde(5, "Joe");
	horde[3].setName("Philippe");
    for (int i = 0; i < 5; i++)
        horde[i].announce();
    delete[] horde;
    return (0);
}