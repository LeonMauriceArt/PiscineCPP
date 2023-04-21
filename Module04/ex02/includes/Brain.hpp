#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		~Brain();
		Brain(const Brain &A);
		Brain& operator=(const Brain &A);
		void setBrain(int i, std::string idea);
		void printBrain() const;
};

#endif