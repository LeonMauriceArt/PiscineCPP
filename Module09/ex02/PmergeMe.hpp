#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>
#include <iostream>
#include <exception>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <limits>
#include <time.h>

typedef std::vector<unsigned int> unIntVector;
typedef std::deque<unsigned int> unIntDeque;

class PmergeMe
{
	private:
		std::vector<unsigned int> _sequenceVector;
		std::deque<unsigned int> _sequenceDeque;
		std::string _before;
		std::string _after;
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		void fillVector(char **args);
		void fillDeque(char **args);
		void vectorInsertionSort(unIntVector vector);
		void vectorMergeInsertion(unIntVector vector);
		void dequeInsertionSort(unIntDeque deque);
		void dequeMergeInsertion(unIntDeque deque);
		void checkInput(char **arguments);
		void getInput(char **arguments);
		void logResult(double vectorTime, double dequeTime, unIntVector sequenceVector, char **args);
	public:
		PmergeMe(char **arguments);
		~PmergeMe();
		class badInputException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif