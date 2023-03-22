#include "Zombie.hpp"

int main()
{
    std::cout << "Creating a zombie on the stack :" << std::endl;
    std::cout << std::endl;
    randomChump("Joe");
    std::cout << std::endl;
    std::cout << "Creating a zombie on the heap :" << std::endl;
    std::cout << std::endl;
    Zombie *z = newZombie("Paupaul");
    z->announce();
    delete z;
    return (0);
}