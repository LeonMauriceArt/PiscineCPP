#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Bureaucrat.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : Form("Default Shrubbery Form", _baseGradeExec, _baseGradeSign), _target("Default target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery creation form", _baseGradeExec, _baseGradeSign), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : Form(other), _target(other.get_target())
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return(*this);
	this->_target = other.get_target();
	Form::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string ShrubberyCreationForm::get_target(void) const
{
	return (_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!(this->isSigned()))
		throw(IsNotSignedException());
	if (executor.getGrade() > this->getGradeToExec())
		throw(GradeTooLowException());
	std::cout << executor.getName() << " executed " << getName() << std::endl;
	std::string filename = this->get_target() + "_shrubbery";
	std::ofstream File(filename.c_str());
	File << "      -X-      \n";
	File << "      / \\      \n";
	File << "     /   \\     \n";
	File << "    / *   \\    \n";
	File << "   /     * \\   \n";
	File << "  /   *     \\  \n";
	File << " /_*_________\\ \n";
	File << "       |       \n";
	File << "   [+] |  [+]  \n";
}