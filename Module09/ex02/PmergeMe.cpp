#include "PmergeMe.hpp"
#include <cstddef>
#include <ctime>
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
}

void PmergeMe::fillVector(char **arguments)
{
	unsigned int element;
	for (size_t i = 0; arguments[i]; ++i)
	{
		element = atof(arguments[i]);
		_sequenceVector.push_back(element);
	}
}

void printVector(unIntVector vector)
{
	for (unIntVector::iterator iter = vector.begin(); iter != vector.end(); ++iter)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::fillDeque(char **arguments)
{
	(void)arguments;
}

PmergeMe::PmergeMe(char **arguments)
{
	checkInput(arguments);
	double vectorTime;
	double dequeTime;
	clock_t start;
	start = clock();
	fillVector(arguments);
	vectorMergeInsertion(_sequenceVector);
	clock_t end = clock();
	vectorTime = ((double)(end - start)) / CLOCKS_PER_SEC;
	start = clock();
	fillDeque(arguments);
	dequeMergeInsertion(_sequenceDeque);
	end = clock();
	dequeTime = ((double)(end - start)) / CLOCKS_PER_SEC;
	logResult(vectorTime, dequeTime, _sequenceVector, arguments);
}

void PmergeMe::logResult(double vectorTime, double dequeTime, unIntVector sortedVector, char **args)
{
	std::cout << "Before : ";
	for (size_t i = 0; args[i]; ++i)
	{
		std::cout << args[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "After : ";
	printVector(sortedVector);
	std::cout << vectorTime << " and " << dequeTime << std::endl;
	(void)sortedVector;
}