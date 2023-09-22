#include "PmergeMe.hpp"

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
		if (std::find(_sequenceVector.begin(), _sequenceVector.end(), element) != _sequenceVector.end())
			throw duplicateException();
		_sequenceVector.push_back(element);
	}
}

void PmergeMe::fillDeque(char **arguments)
{
	unsigned int element;
	for (size_t i = 0; arguments[i]; ++i)
	{
		element = atof(arguments[i]);
		if (std::find(_sequenceDeque.begin(), _sequenceDeque.end(), element) != _sequenceDeque.end())
			throw duplicateException();
		_sequenceDeque.push_back(element);
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

bool isSorted(char **arguments)
{
	unsigned int element;
	unIntVector test;
	for (size_t i = 0; arguments[i]; ++i)
	{
		element = atof(arguments[i]);
		test.push_back(element);
	}
	unIntVector::const_iterator it;
	for (it = test.begin(); it != test.end() - 1; ++it)
	{
		if (*it > *(it + 1))
			return false;
	}
	return true;
}

PmergeMe::PmergeMe(char **arguments)
{
	checkInput(arguments);
	if (isSorted(arguments))
		throw alreadySortedException();
	clock_t start, end;
	double vectorExecTime, dequeExecTime;
	vectorExecTime = 0.0;
	dequeExecTime = 0.0;
	
	//VECTOR EXEC
	start = clock();
	fillVector(arguments);
	vectorMergeInsertion(_sequenceVector);
	end = clock();
	vectorExecTime += ((double) (end - start)) / CLOCKS_PER_SEC;
	
	//DEQUE EXEC
	start = clock();
	fillDeque(arguments);
	dequeMergeInsertion(_sequenceDeque);
	end = clock();
	dequeExecTime += ((double) (end - start)) / CLOCKS_PER_SEC;

	//DISPLAYING RESULTS
	logResult(vectorExecTime, dequeExecTime, _sequenceVector, arguments);
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
	std::cout << "Time to process a range of " << sortedVector.size() << " elements with std::vector : " << vectorTime * 1000 << " milliseconds"<< std::endl;
	std::cout << "Time to process a range of " << sortedVector.size() << " elements with std::deque : " << dequeTime * 1000 << " milliseconds" << std::endl;
}