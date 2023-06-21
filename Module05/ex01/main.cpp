#include "./includes/Bureaucrat.hpp"
#include "./includes/Form.hpp"

int main()
{
	try
	{
		Form s("Lol", 5, 5);
		Form f("MERDE", 140, 140);
		Bureaucrat Henry("Henry", 120);
		Henry.signForm(f);
		Henry.signForm(s);
	}
	catch(const std::exception& e)
	{
		std::cerr << "An error was encountered : " << e.what() << '\n';
	}
	return (0);
}