#include "easyfind.hpp"
#include <exception>
#include <iterator>
#include <vector>
#include <list>

void testVector()
{
	std::cout << BOLDYELLOW << "---Starting vector container test---" << RESET << std::endl;
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
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << BOLDYELLOW << "---End of test---" << RESET << std::endl;
	return;
}

void testList()
{
	std::cout << BOLDYELLOW << "---starting list container test---" << RESET << std::endl;
	std::list<int> list;
	list.push_back(42);
	list.push_back(12);
	list.push_back(55);
	try
	{
		std::list<int>::iterator iter;
		iter = ::easyfind(list, 42);
		std::cout << GREEN << *iter << RESET << std::endl;
		iter = ::easyfind(list, 6);
		std::cout << YELLOW << *iter << RESET << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << BOLDYELLOW << "---End of test---" << RESET << std::endl;
	return;
}

int main()
{
	testVector();
	testList();
	return 0;
}