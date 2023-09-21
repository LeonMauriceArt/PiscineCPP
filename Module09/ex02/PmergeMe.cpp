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
<<<<<<< HEAD
	checkInput(++arguments); //++arguments to skip the first arg, the program name
	//getInput(++arguments);
	time_t VectorSortTime = 0;
	time_t DequeSortTime = 0;
	mergeInsertionSort(this->sequenceVector);
	mergeInsertionSort(this->sequenceDeque);
	logResult(VectorSortTime, DequeSortTime, sequenceVector);
=======
	checkInput(arguments);
	getInput(arguments);
	logResult();
>>>>>>> ae364228e7ee7c95e8175d4b255305fd1caab644
}

void PmergeMe::logResult(time_t vectorTime, time_t dequeTime, std::vector<unsigned int> sortedVector)
{
<<<<<<< HEAD
	std::cout << vectorTime << " and " << dequeTime << std::endl;
	(void)sortedVector;
=======
	std::cout << "Before: " << _before << std::endl;
	std::cout << "After: " << _after << std::endl;

}

const char* PmergeMe::alreadySortedException::what() const throw()
{
	return ("Error: the number sequence is already sorted.");
}

const char* PmergeMe::negativeNumberException::what() const throw()
{
	return ("Error: the number sequence is already sorted.");
}

PmergeMe::badInputException::badInputException(std::string errorInput)
{
        std::string message = "Error: bad input => ";
        message.append(errorInput);
        errorMessage = message;
}

PmergeMe::badInputException::~badInputException() throw() 
{
}

const char *PmergeMe::badInputException::what() const throw()
{
        return (errorMessage.c_str());
>>>>>>> ae364228e7ee7c95e8175d4b255305fd1caab644
}