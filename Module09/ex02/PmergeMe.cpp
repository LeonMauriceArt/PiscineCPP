#include "PmergeMe.hpp"
#include <bits/types/time_t.h>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <vector>

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
	{
		for (size_t j = 0; arguments[i][j]; ++j)
		{
			if (!std::isdigit(arguments[i][j]))
				throw badInputException();
		}
		double value = atof(arguments[i]);
		if (value > std::numeric_limits<unsigned int>::max())
			throw badInputException();
	}
	std::cout << "Good input !" << std::endl;
	return;
}

void PmergeMe::getInput(char **arguments)
{
	(void)arguments;
}

PmergeMe::PmergeMe(char **arguments)
{
	checkInput(++arguments); //++arguments to skip the first arg, the program name
	//getInput(++arguments);
	time_t VectorSortTime = 0;
	time_t DequeSortTime = 0;
	mergeInsertionSort(this->sequenceVector);
	mergeInsertionSort(this->sequenceDeque);
	logResult(VectorSortTime, DequeSortTime, sequenceVector);
}

void PmergeMe::logResult(time_t vectorTime, time_t dequeTime, std::vector<unsigned int> sortedVector)
{
	std::cout << vectorTime << " and " << dequeTime << std::endl;
	(void)sortedVector;
}