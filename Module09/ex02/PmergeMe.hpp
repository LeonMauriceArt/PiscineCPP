#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>
#include <iostream>
#include <exception>

class PmergeMe
{
	private:
		std::vector<unsigned int> sequenceVector;
		std::deque<unsigned int> sequenceDeque;
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		void checkInput(char **arguments);
	public:
		PmergeMe(char **arguments);
		~PmergeMe();
		void logResult();
		class negativeNumberException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class badInputException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};


#endif