#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain created" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destroyed" << std::endl;
}

Brain::Brain(const Brain& brain)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
}

Brain& Brain::operator=(const Brain& brain)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
	return (*this);
}

void Brain::setBrain(int i, std::string idea)
{
	this->ideas[i] = idea;
}

void Brain::printBrain() const
{
	for (int i = 0; i < 100; i++)
		std::cout << this->ideas[i] << std::endl;
}