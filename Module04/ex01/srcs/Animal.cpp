#include "../includes/Animal.hpp"

Animal::Animal()
{
	this->type = "Some type of animal";
	std::cout << "Animal created" << std::endl;
}

Animal::Animal(const Animal &other)
{
	this->type = other.type;
}

Animal &Animal::operator=(const Animal &other)
{
	this->type = other.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destroyed" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "*An unknown animal makes a sound*" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}
