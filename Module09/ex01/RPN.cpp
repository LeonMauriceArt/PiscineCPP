#include "RPN.hpp"
#include <limits>

RPN::RPN()
{

}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN &RPN::operator=(const RPN &other)
{
	numStack = other.numStack;
	return (*this);
}

RPN::~RPN()
{

}

const char* RPN::badExpressionException::what() const throw()
{
	return ("Error: bad expression input.");
}

const char* RPN::resultOverflowException::what() const throw()
{
	return ("Error: result is int overflowing.");
}

bool RPN::isOperator(const char c)
{
	if (c != '+' && c != '-' && c != '/' && c != '*')
		return false;
	return (true);
}

bool RPN::checkInput(std::string &expression)
{
	std::istringstream iss(expression);
	std::string element;
	while (iss >> element)
	{
		if (element.size() > 1)
			return false;
	}
	expression.erase(std::remove(expression.begin(), expression.end(), ' '), expression.end());
	for (size_t i = 0; expression[i]; ++i)
	{
		if (!std::isdigit(expression[i]))
		{
			if (!isOperator(expression[i]))
				return (false);
		}
	}
	return (true);
}

RPN::RPN(std::string expression)
{
	if (!checkInput(expression))
		throw badExpressionException();
	reversePolishCalculation(expression);
}

int RPN::operate(int a, int b, char operatorCase)
{
	long long result = 0;
	switch (operatorCase) 
	{
		case ('+'):
		{
			result = a + b;
			if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
				throw resultOverflowException();
			return static_cast<int>(result);
		}
		case ('-'):
		{
			result = a - b;
			if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
				throw resultOverflowException();
			return static_cast<int>(result);
		}
		case ('/'):
		{
			result = a / b;
			if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
				throw resultOverflowException();
			return static_cast<int>(result);
		}
		case ('*'):
		{
			result = a * b;
			std::cout << "long double result of " << a << " * " << b << " is " << result << std::endl;
			std::cout << "max is " << std::numeric_limits<int>::max() << std::endl;
			if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
				throw resultOverflowException();
			return static_cast<int>(result);
		}
		default:
			throw badExpressionException();
	}
}

void RPN::reversePolishCalculation(std::string expression)
{
	int result;
	for (size_t i = 0; expression[i]; ++i)
	{
		if (std::isdigit(expression[i]))
			numStack.push(expression[i] - '0');
		else if (isOperator(expression[i]))
		{
			if (numStack.size() < 2)
				throw badExpressionException();
			result = numStack.top();
			numStack.pop();
			result = operate(result, numStack.top(), expression[i]);
			numStack.pop();
			numStack.push(result);
		}
	}
	if (numStack.size() != 1)
		throw badExpressionException();
	std::cout << result << std::endl;
}
