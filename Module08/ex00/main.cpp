#include "easyfind.hpp"
#include <exception>
#include <iterator>
#include <vector>

void testVector()
{
	std::vector<int> vector;
	vector.push_back(42);
	vector.push_back(21);
	vector.push_back(42);
	try
	{
		std::vector<int>::iterator iter;
		iter = ::easyfind(vector, 21);
		std::cout << GREEN << *iter << RESET << std::endl;
		iter = ::easyfind(vector, 6);
		std::cout << YELLOW << *iter << RESET << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << YELLOW << e.what() << RESET << std::endl;
	}
	return;
}

void testList()
{
	return;
}

int main()
{
	testVector();
	testList();
	return 0;
}