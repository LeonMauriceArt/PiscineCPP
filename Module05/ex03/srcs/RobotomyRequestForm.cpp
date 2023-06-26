#include "../includes/Form.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include <stdlib.h>
#include <cstdlib>
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm() : Form("Default Robotomy Form", _baseGradeExec, _baseGradeSign), _target("Default target")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string name, std::string target) : Form(name, _baseGradeExec, _baseGradeSign), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : Form(other), _target(other.get_target())
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this == &other)
		return (*this);
	this->_target = other.get_target();
	Form::operator=(other);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

std::string RobotomyRequestForm::get_target(void) const
{
	return (_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExec())
		throw(GradeTooLowException());
	srand(time(NULL));
	std::cout << "*Drill noises*" << std::endl;
	int random = rand() % 2;
	if (random)
		std::cout << _target << " has been successfully robotomized !" << std::endl;
	else
		std::cout << "Robotomize operation failed..." << std::endl;
}