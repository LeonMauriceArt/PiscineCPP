#include "Span.hpp"
#include <algorithm>
#include <cmath>
#include <exception>
#include <iterator>
#include <limits.h>
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
		std::list<int>::const_iterator iter = numbers.begin();
		for(; iter != numbers.end(); ++iter)
		{
			for (std::list<int>::const_iterator niter = numbers.begin(); niter != numbers.end(); ++niter)
			{
				if (iter != niter)
				{
					unsigned int curr_dist = abs(abs(*niter) - abs(*iter));
					min_dist = std::min(min_dist, curr_dist);
				}
			}
		}
	} catch (std::exception &e) 
	{
		std::cout << RED << e.what() << RESET << std::endl;
		return 0;
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