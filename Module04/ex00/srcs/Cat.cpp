#include "../includes/Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Animal of type Cat created" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destroyed" << std::endl;
}

Cat::Cat(const Cat &other): Animal()
{
	this->type = other.type;
}

Cat &Cat::operator=(const Cat &other)
{
	this->type = other.type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Miiiaaaouu" << std::endl;
}