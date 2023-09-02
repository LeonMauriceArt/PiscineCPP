#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:
		std::stack<int> numStack;
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
	public:
		RPN
		~RPN();
		void	reversePolishCalculation(char **av);
};


#endif