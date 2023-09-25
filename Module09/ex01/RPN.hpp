#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <iostream>
#include <stack>
#include <cstddef>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <sstream>

class RPN
{
	private:
		std::stack<int> numStack;
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		bool isOperator(const char c);
		bool checkInput(std::string &expression);
		int	operate(int a, int b, char operatorChar);
	public:
		RPN(std::string expression);
		~RPN();
		void	reversePolishCalculation(std::string expression);
		class badExpressionException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class divideZeroException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class resultOverflowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif