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

int	Intern::whatForm(std::string form)
{
	std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	for (int i = 0; i <= 3; i++)
	{
		std::cout << i << std::endl;
		if (form.compare(forms[i]) == 0)
			return (i);
	}
	return (-1);
}

Form *Intern::makeForm(std::string form, std::string target)
{
	switch (whatForm(form))
	{
		case 0:
			std::cout << "Intern creates presidential pardon form" << std::endl;
			return (new PresidentialPardonForm(form, target));
		case 1:
			std::cout << "Intern creates robotomy request form" << std::endl;
			return (new RobotomyRequestForm(form, target));
		case 2:
			std::cout << "Intern creates shrubbery creation form" << std::endl;
			return (new ShrubberyCreationForm(form, target));
		default:
			std::cout << "The Intern could not create " << form << " form, because it is unknown" << std::endl;
	}
	return (NULL);
}