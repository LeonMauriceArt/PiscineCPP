#include "../includes/Animal.hpp"

Animal::Animal(const Animal &A)
{
	this->type = A.type;
}

Animal &Animal::operator=(const Animal &A)
{
	this->type = A.type;
	return (*this);
}

Animal::Animal()
{
	std::cout << "Animal created" << std::endl;
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
