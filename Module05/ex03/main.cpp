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
		Bureaucrat *man = new Bureaucrat("Henry", 40);
		Form *rrf;
		Form *ppf;
		Form *randomForm;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
		randomForm = rrf;
		// man->signForm(*randomForm);
		// man->executeForm(*randomForm);
		delete(rrf);
		delete(ppf);
		delete(man);
	}
	catch(const std::exception& e)
	{
		std::cerr << "An error was encountered : " << e.what() << '\n';
	}
	return (0);
}