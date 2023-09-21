#include "PmergeMe.hpp"

const char *PmergeMe::badInputException::what() const throw()
{
	return ("Error: bad input.");
}