#include "./includes/Bureaucrat.hpp"
#include "./includes/Form.hpp"
#include "./includes/ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		ShrubberyCreationForm form;
		Bureaucrat Henry("Henry", 120);
		Henry.signForm(form);
		Henry.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << "An error was encountered : " << e.what() << '\n';
	}
	return (0);
}