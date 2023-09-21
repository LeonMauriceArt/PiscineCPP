#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <bits/types/time_t.h>
#include <ctime>
#include <deque>
#include <vector>
#include <iostream>
#include <exception>

typedef std::vector<unsigned int> unIntVector;
typedef std::deque<unsigned int> unIntDeque;

class PmergeMe
{
	private:
		unIntVector sequenceVector;
		unIntDeque sequenceDeque;
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		void vectorInsertionSort(unIntVector vector);
		void vectorMergeInsertion(unIntVector vector);
		void dequeInsertionSort(unIntDeque deque);
		void dequeMergeInsertion(unIntDeque deque);
		void checkInput(char **arguments);
		void getInput(char **arguments);
		void logResult(time_t vectorTime, time_t dequeTime, std::vector<unsigned int> sequenceVector);
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