#include "Array.hpp"

void intTest()
{
	std::cout << YELLOW << "---Int Array Test---" << RESET << std::endl;
	Array<int> intArray(5);
	intArray[5] = 12;
	std::cout << "Array size = " << intArray.size() << std::endl;
	std::cout << intArray[5] << std::endl;
	std::cout << intArray[-5] << std::endl;
	Array<int> test(10);
	test[5] = 42;
	test.displayArray();
	{
		Array<int> copy;
		copy = test;
		std::cout << test[5] << " - " << copy[5] << std::endl;
	}
	std::cout << test[5] << std::endl;
}

void charTest()
{
	std::cout << YELLOW << "---Char Array Test---" << RESET << std::endl;
	Array<char> charArray(1);
	charArray[1] = 'F';
	Array<char> test(charArray);
	charArray.displayArray();
	test.displayArray();
	// Array<char> empty;
	// std::cout << "empty " << empty[0] << std::endl;
	// std::cout << empty[1] << std::endl;
}

int main(void)
{
	intTest();
	charTest();
	return(0);
}