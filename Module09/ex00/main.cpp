#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
		std::cout << "Error : the program needs a file as input. Exemple : ./btc input.txt" << std::endl;
	std::string input(av[1]);
	BitcoinExchange exchange(input);
	return (0);
}