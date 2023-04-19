#include "../includes/WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "Animal of type WrongCat created" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destroyed" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Miiirrrgggaaaouu" << std::endl;
}