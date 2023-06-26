#include "../includes/Form.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Default Presidential Form", _baseGradeExec, _baseGradeSign), _target("Default target")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string name, std::string target) : Form(name, _baseGradeExec, _baseGradeSign), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : Form(other), _target(other.get_target())
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this == &other)
		return (*this);
	this->_target = other.get_target();
	Form::operator=(other);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

std::string PresidentialPardonForm::get_target(void) const
{
	return (_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExec())
		throw(GradeTooLowException());
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl; 
}