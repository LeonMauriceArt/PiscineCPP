#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(const WrongAnimal &A)
{
	this->type = A.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &A)
{
	this->type = A.type;
	return (*this);
}

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal created" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destroyed" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "*An unknown animal makes a sound*" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}
