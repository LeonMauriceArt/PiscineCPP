#include "./includes/Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat henry("Henry", 140);
		for(int i = 0; i < 141; i++)
		{
			henry.promotion();
			std::cout << henry << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "An error was encountered : " << e.what() << '\n';
	}
	return (0);
}