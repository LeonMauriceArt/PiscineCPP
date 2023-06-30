#include "../includes/Intern.hpp"
#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

Intern::Intern()
{
	std::cout << "New Intern created." << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destroyed." << std::endl;
}

Form *Intern::makeForm(std::string form, std::string target)
{
	std::string forms[3] = {
		"presidential pardon", 
		"robotomy request", 
		"shrubbery creation"
	};
	void(Intern::*ptr_func[3])(void)={
		Intern::CreatePresidential(target),
		Intern::CreateRobotomy(target),
		Intern::CreateShrubbery(target)
	}

	switch (whatForm(form))
	{
		case 0:
			std::cout << "Intern creates presidential pardon form" << std::endl;
			return (new PresidentialPardonForm(target));
		case 1:
			std::cout << "Intern creates robotomy request form" << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern creates shrubbery creation form" << std::endl;
			return (new ShrubberyCreationForm(target));
		default:
			std::cout << "The Intern could not create " << form << " form, because it is unknown" << std::endl;
	}
	return (NULL);
}