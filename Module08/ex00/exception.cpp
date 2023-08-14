#include "easyfind.hpp"

const char *notInContainer::what() const throw()
{
	return ("Error: The integer you tried to find is not in the container.");
}