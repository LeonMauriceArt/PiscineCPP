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

void PmergeMe::getInput(char **arguments)
{
	(void)arguments;
}

PmergeMe::PmergeMe(char **arguments)
{
	checkInput(arguments);
	getInput(arguments);
	logResult();
}

void PmergeMe::logResult()
{
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
}