#include "iter.hpp"

void testprint(int &value)
{
	std::cout << value << std::endl;
}

void incrementprint(int &value)
{
	value += 1;
	templateprint(value);
}

int main(void)
{
	int inttab[] = {0,1,2,3,4,5};
	std::string strtab[] = {"lol", "salut", "test"};

	::iter(inttab, 6, incrementprint);
	::iter(strtab, 3, ::templateprint);
	return 0;
}