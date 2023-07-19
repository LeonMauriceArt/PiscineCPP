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
		Form *scf;
		Form *randomForm;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
		scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		randomForm = rrf;
		man->executeForm(*randomForm);
		man->signForm(*randomForm);
		man->signForm(*scf);
		man->executeForm(*scf);
		delete(rrf);
		delete(ppf);
		delete(man);
		delete(scf);
	}
	catch(const std::exception& e)
	{
		std::cerr << "An error was encountered : " << e.what() << '\n';
	}
	return (0);
}