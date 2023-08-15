#include "Span.hpp"
#include <algorithm>
#include <cmath>
#include <exception>
#include <iterator>
#include <limits>
#include <list>

Span::Span(): N(10)
{
}

Span::~Span()
{
}

Span::Span(unsigned int maxNumbers): N(maxNumbers)
{
}

Span::Span(const Span &other): N(other.N)
{
	this->numbers = other.numbers;
}

Span &Span::operator=(const Span &other)
{
	this->N = other.N;
	this->numbers = other.numbers;
	return (*this);
}

void Span::addNumber(unsigned int number)
{
	try 
	{
		if (numbers.size() == N)
			throw classSpanFull();
		numbers.push_back(number);
	} 
	catch (std::exception &e) 
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

unsigned int Span::shortestSpan() const
{
	unsigned int min_dist = std::numeric_limits<unsigned int>::max();
	try 
	{
		if (numbers.empty() == 1 || numbers.size() == 1)
			throw cannotGetDistance();
	} 
	catch (std::exception &e) 
	{
		std::cout << RED << e.what() << RESET << std::endl;
		return 0;
	}
	std::list<int> sorted = numbers;
	sorted.sort();
	for(std::list<int>::iterator iter = sorted.begin(), next = iter++; iter != sorted.end() && next != sorted.end(); ++iter, ++next)
	{
		unsigned int current_dist = abs(*iter - *next);
		min_dist = std::min(min_dist, current_dist);
	}
	return min_dist;
}

unsigned int Span::longestSpan() const
{
	unsigned int max_dist;
	try 
	{
		if (numbers.empty() == 1 || numbers.size() == 1)
			throw cannotGetDistance();
		max_dist = *std::max_element(numbers.begin(), numbers.end()) - *std::min_element(numbers.begin(), numbers.end());
	} catch (std::exception &e) 
	{
		std::cout << RED << e.what() << RESET << std::endl;
		return 0;
	}
	return max_dist;
}

const char *Span::classSpanFull::what() const throw()
{
	return ("Error: cannot add a number, class Span is full.");
}

const char *Span::cannotGetDistance::what() const throw()
{
	return ("Error: cannot get a valid distance in the class Span.");
}

void Span::addRange(std::list<int>::iterator start, std::list<int>::iterator end)
{
	try
	{
		std::list<int>::iterator iter = start;
		for(; iter != end; ++iter)
			addNumber(*iter);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}