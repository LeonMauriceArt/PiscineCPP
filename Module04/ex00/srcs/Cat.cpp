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

void Cat::makeSound() const
{
	std::cout << "Miiiaaaouu" << std::endl;
}