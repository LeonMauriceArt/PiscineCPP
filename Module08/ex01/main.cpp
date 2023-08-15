#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(50);
	sp.addNumber(3);
	sp.addNumber(255);
	sp.addNumber(9);
	sp.addNumber(-257);

	std::list<int> range;
	range.push_back(51);
	range.push_back(42);
	range.push_back(5);
	range.push_back(12);

	Span rangeSpan(4);
	rangeSpan.addRange(range.begin(), range.end());

	std::cout << "Shortest distance = " << sp.shortestSpan() << std::endl;
	std::cout << "Longest distance = " << sp.longestSpan() << std::endl;
	std::cout << "Shortest distance = " << rangeSpan.shortestSpan() << std::endl;
	std::cout << "Longest distance = " << rangeSpan.longestSpan() << std::endl;
	return 0;
}