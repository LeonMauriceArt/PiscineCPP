#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac <= 2)
	{
		std::cout << "Error: the program needs a sequence of positive integers to sort." << std::endl;
		return 1;
	}
	try 
	{
		PmergeMe sort(++av);
	} 
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}