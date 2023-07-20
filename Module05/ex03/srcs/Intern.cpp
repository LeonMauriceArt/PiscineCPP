#include "../includes/Intern.hpp"
#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include <string>

typedef Form *(Intern::*ptr_func)(std::string);

Intern::Intern()
{
	std::cout << "New Intern created." << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << "New Intern created by copy." << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destroyed." << std::endl;
}

Form *Intern::CreatePresidential(std::string target)
{
	std::cout << "Intern creates presidential pardon form." << std::endl;
	return(new PresidentialPardonForm(target));
}

Form *Intern::CreateRobotomy(std::string target)
{
	std::cout << "Intern creates robotomy request form." << std::endl;
	return(new RobotomyRequestForm(target));
}

Form *Intern::CreateShrubbery(std::string target)
{
	std::cout << "Intern creates shrubbery creation form." << std::endl;
	return(new ShrubberyCreationForm(target));
}

Form *Intern::makeForm(std::string form, std::string target)
{
	std::string forms[3] = {
		"presidential pardon", 
		"robotomy request", 
		"shrubbery creation"
	};
	ptr_func functions[3]={
		&Intern::CreatePresidential,
		&Intern::CreateRobotomy,
		&Intern::CreateShrubbery
	};
	for(int i = 0; i < 3; i++)
	{
		if (form == forms[i])
			return((this->*functions[i])(target));
	}
	return (NULL);
}