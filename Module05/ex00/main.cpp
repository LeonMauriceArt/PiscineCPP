#include "./includes/Bureaucrat.hpp"

int main()
{
	Bureaucrat henry("Henry", 56);
	{
		Bureaucrat bob(henry);
	}
	std::cout << henry << std::endl;
	return (0);
}