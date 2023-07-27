#include "iter.hpp"

void testprint(const int &value)
{
	std::cout << value << std::endl;
}

int main(void)
{
	int tab[] = {0,1,2,3,4,5};
	std::string strtab[] = {"lol", "salut", "test"};

	::iter(tab, 5, testprint);
	::iter(strtab, 3, ::print);
	return 0;
}