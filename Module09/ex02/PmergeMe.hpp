#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>
#include <iostream>
#include <exception>
#include <ctime>
#include <limits>
#include <algorithm>

typedef std::vector<unsigned int> unIntVector;
typedef std::deque<unsigned int> unIntDeque;

class PmergeMe
{
	private:
		std::vector<unsigned int> _sequenceVector;
		std::deque<unsigned int> _sequenceDeque;
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		void fillVector(char **args);
		void fillDeque(char **args);
		void vectorMergeInsertion(unIntVector &vector);
		void dequeMergeInsertion(unIntDeque &deque);
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
		class duplicateException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class alreadySortedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif