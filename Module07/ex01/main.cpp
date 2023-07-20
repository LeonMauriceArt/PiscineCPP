#include "iter.hpp"

int main(void)
{
	int tab[] = {0,1,2,3,4,5};
	std::string strtab[] = {"lol", "salut", "test"};

	::iter(tab, 5, ::print);
	::iter(strtab, 3, ::print);
	return 0;
}