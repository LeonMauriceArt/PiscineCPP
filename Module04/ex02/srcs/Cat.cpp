#include "../includes/Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Animal of type Cat created" << std::endl;
}

Cat::~Cat()
{
	delete(this->brain);
	std::cout << "Cat destroyed" << std::endl;
}

Cat::Cat(const Cat &other): Animal()
{
	this->type = other.type;
	this->brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other)
{
	delete (this->brain);
	this->type = other.type;
	this->brain = new Brain(*other.brain);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Miiiaaaouu" << std::endl;
}

void Cat::think()
{
	this->brain->setBrain(50, "Je veux un poisson");
}

void Cat::remember()
{
	this->brain->printBrain();
}