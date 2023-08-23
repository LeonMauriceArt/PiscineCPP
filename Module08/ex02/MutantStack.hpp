#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

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

#include <iostream>
#include <list>
#include <stdlib.h>
#include <stack>
#include <algorithm>
#include <iterator>
#include <deque>

template <typename T, class container=std::deque<T> > 
class MutantStack : public std::stack<T>
{
	public:
		typedef typename container::iterator iterator;
		typedef std::reverse_iterator<T> reverse_iterator;

		MutantStack() : std::stack<T>() {};
		~MutantStack() {};
		MutantStack(const MutantStack &other) : std::stack<T>(other){};
		MutantStack &operator=(const MutantStack &other)
		{
			if (*this != other)
				std::stack<T>::operator=(other);
			return *this;
		}
		iterator begin() { return this->c.begin();}
		iterator end() { return this->c.end();}
		reverse_iterator rbegin() { return reverse_iterator(this->crbegin());}
		reverse_iterator rend() { return reverse_iterator(this->crend());}
};

#endif