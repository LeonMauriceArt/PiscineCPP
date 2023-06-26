#include "./includes/Bureaucrat.hpp"
#include "./includes/Form.hpp"
#include "./includes/ShrubberyCreationForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/Intern.hpp"

int main()
{
	try
	{
		Intern someRandomIntern;
		Form *rrf;
		Form *scf;
		Form *ppf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
		delete(rrf);
		delete(scf);
		delete(ppf);
	}
	catch(const std::exception& e)
	{
		std::cerr << "An error was encountered : " << e.what() << '\n';
	}
	return (0);
}