#include "RPN.hpp"

bool	checkInput(std::string expression)
{
	(void)expression;
	return (true);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: need a reverse polish expression as argument." << std::endl << "Example: \"1 1 +\"" << std::endl;
		return (1);
	}
	std::string expression(av[1]);
	if (!checkInput(expression))
	{
		std::cout << "Error: bad input." << std::endl;
		return (1);
	}
	return (0);
}