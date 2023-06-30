#include "./includes/Bureaucrat.hpp"
#include "./includes/Form.hpp"

int main()
{
	Form *lolForm;
	Form *merdeForm;
	try
	{
		lolForm = new Form("Lol", 5, 5);
		merdeForm = new Form("MERDE", 140, 140);
		Bureaucrat Henry("Henry", 120);
		Henry.signForm(*merdeForm);
		Henry.signForm(*lolForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << "An error was encountered : " << e.what() << '\n';
	}
	delete(lolForm);
	delete(merdeForm);
	return (0);
}