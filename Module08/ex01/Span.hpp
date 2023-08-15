#ifndef SPAN_HPP
#define SPAN_HPP

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#include <algorithm>
#include <iostream>
#include <list>
#include <stdlib.h>

class Span
{
	private:
		std::list<int> numbers;
		unsigned int N;
		Span();
	public:
		class classSpanFull: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class cannotGetDistance: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		Span(unsigned int N);
		Span(const Span &other);
		~Span();
		Span &operator=(const Span &other);
		void addNumber(unsigned int number);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		void	addRange(std::list<int>::iterator start, std::list<int>::iterator end);
};

#endif