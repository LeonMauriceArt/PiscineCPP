#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>
#include <iostream>
#include <exception>

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
		void checkInput(char **arguments);
		void getInput(char **arguments);
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