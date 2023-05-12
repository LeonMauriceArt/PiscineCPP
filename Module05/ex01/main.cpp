#include "./includes/Bureaucrat.hpp"
#include "./includes/Form.hpp"

int main()
{
	try
	{
		Form f("MERDE", 140, 140);
		Bureaucrat Henry("Henry", 120);
		Henry.signForm(f);
		Henry.signForm(f);
	}
	catch(const std::exception& e)
	{
		std::cerr << "An error was encountered : " << e.what() << '\n';
	}
	return (0);
}