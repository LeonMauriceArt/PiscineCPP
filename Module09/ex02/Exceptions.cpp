#include "PmergeMe.hpp"

const char *PmergeMe::badInputException::what() const throw()
{
	return ("Error: bad input.");
}

const char *PmergeMe::duplicateException::what() const throw()
{
	return ("Error: your input has a duplicate number.");
}

const char *PmergeMe::alreadySortedException::what() const throw()
{
	return ("Error: the sequence provided is already sorted.");
}