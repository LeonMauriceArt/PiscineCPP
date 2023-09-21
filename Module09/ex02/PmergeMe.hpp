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
<<<<<<< HEAD
		unIntVector sequenceVector;
		unIntDeque sequenceDeque;
=======
		std::vector<unsigned int> _sequenceVector;
		std::deque<unsigned int> _sequenceDeque;
		std::string _before;
		std::string _after;
>>>>>>> ae364228e7ee7c95e8175d4b255305fd1caab644
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		void vectorInsertionSort(unIntVector vector);
		void vectorMergeInsertion(unIntVector vector);
		void dequeInsertionSort(unIntDeque deque);
		void dequeMergeInsertion(unIntDeque deque);
		void checkInput(char **arguments);
		void getInput(char **arguments);
<<<<<<< HEAD
		void logResult(time_t vectorTime, time_t dequeTime, std::vector<unsigned int> sequenceVector);
	public:
		PmergeMe(char **arguments);
		~PmergeMe();
=======
		void logResult();
		void sortVector();
		void sortDeque();
	public:
		PmergeMe(char **arguments);
		~PmergeMe();
		class negativeNumberException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
>>>>>>> ae364228e7ee7c95e8175d4b255305fd1caab644
		class badInputException : public std::exception
		{
			private:
					std::string errorMessage;
			public:
					virtual ~badInputException() throw();
					badInputException(std::string line);
					virtual const char* what() const throw();
		};
		class alreadySortedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif