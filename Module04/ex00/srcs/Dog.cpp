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

Dog::Dog(const Dog &other): Animal()
{
	this->type = other.type;
}

Dog &Dog::operator=(const Dog &other)
{
	this->type = other.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Ouaaf ouafff ouaaff" << std::endl;
}