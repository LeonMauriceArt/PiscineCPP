#include "./includes/Bureaucrat.hpp"

int main()
{
	Bureaucrat* henry;
	try
	{
		henry = new Bureaucrat("Henry", 100);
		for(int i = 0; i < 141; i++)
		{
			henry->demotion();
			std::cout << *henry << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "An error was encountered : " << e.what() << '\n';
	}
	delete(henry);
	return (0);
}