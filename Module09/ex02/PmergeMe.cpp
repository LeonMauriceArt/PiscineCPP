#include "PmergeMe.hpp"
#include <cstddef>

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return (*this);
}

void PmergeMe::checkInput(char **arguments)
{
	for (size_t i = 0; arguments[i]; ++i)
		std::cout << arguments[i] << std::endl;
	return;
}

PmergeMe::PmergeMe(char **arguments)
{
	checkInput(++arguments); //++arguments to skip the first arg, the program name
	logResult();
}

void PmergeMe::logResult()
{

}