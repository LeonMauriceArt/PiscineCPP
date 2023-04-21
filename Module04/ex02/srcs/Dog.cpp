#include "../includes/Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Animal of type Dog created" << std::endl;
}

Dog::~Dog()
{
	delete (this->brain);
	std::cout << "Dog destroyed" << std::endl;
}

Dog::Dog(const Dog &other): Animal()
{
	this->type = other.type;
	this->brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other)
{
	this->type = other.type;
	*this->brain = *(other.brain);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Ouaaf ouafff ouaaff" << std::endl;
}

void Dog::think()
{
	this->brain->setBrain(50, "Je veux un os");
}

void Dog::remember()
{
	this->brain->printBrain();
}