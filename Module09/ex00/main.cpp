#include "BitcoinExchange.hpp"
#include "Date.hpp"
#include <iostream>

int main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		Date date("2019-02-12");
		std::cout << "Error : the program needs a file as input. Exemple : ./btc input.txt" << std::endl;
		return(1);
	}
	std::string input(av[1]);
	BitcoinExchange exchange(DATABASE);
	return (0);
}