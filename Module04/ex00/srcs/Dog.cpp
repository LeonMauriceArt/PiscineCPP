#include "../includes/Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Animal of type Dog created" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Ouaaf ouafff ouaaff" << std::endl;
}