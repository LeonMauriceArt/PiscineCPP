#include "Span.hpp"

int main()
{
	Span sp = Span(10000);

	for (int i = 0; i < 10000; i++)
		sp.addNumber(i);
	// sp.addNumber(-200);
	// sp.addNumber(3);
	// sp.addNumber(255);
	// sp.addNumber(9);
	// sp.addNumber(256);

	std::cout << "Shortest distance = " << sp.shortestSpan() << std::endl;
	std::cout << "Longest distance = " << sp.longestSpan() << std::endl;
	return 0;
}