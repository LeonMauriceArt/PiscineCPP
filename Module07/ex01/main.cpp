#include "iter.hpp"

template<typename T> void print(T &x)
{
	std::cout << x << std::endl;
}

void printplus(int num)
{
	std::cout << num + 1 << std::endl;
}

int main(void)
{
	int tab[] = {0,1,2,3,4,5};
	std::string strtab[] = {"lol", "salut", "test"};

	::iter(tab, 5, print);
	::iter(tab, 5, printplus);
	return 0;
}