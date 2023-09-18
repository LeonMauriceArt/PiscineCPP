#include "./includes/BitcoinExchange.hpp"
#include "./includes/Exceptions.hpp"
#include "./includes/Date.hpp"
#include <exception>

int main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		std::cout << "Error: need a file as input." << std::endl;
		return(1);
	}
	std::string filename(av[1]);
	try 
	{
		BitcoinExchange exchange(DATABASE);
		exchange.printExchangeValues(filename);
	} 
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}