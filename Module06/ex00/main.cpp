#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage : enter a single argument that is a litteral (char, int, float or double)" << std::endl;
		return (0);
	}
	std::string litteral(av[1]);
	ScalarConverter::convert(litteral);
	return (0);
}