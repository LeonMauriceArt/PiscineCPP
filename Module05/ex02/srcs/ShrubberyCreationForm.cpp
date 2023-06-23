#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Bureaucrat.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : Form("Default Shrubbery Form", 137, 145), _target("Default target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string target) : Form(name, 137, 145), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : Form(other.getName(), 137, 145), _target(other.get_target())
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	this->_target = other.get_target();
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
	if (executor.getGrade() > this->getGradeToExec())
		throw(GradeTooLowException());
	std::string filename = this->get_target() + "_shrubbery";
	std::ofstream File(filename.c_str());
	File << "       ^       \n";
	File << "      / \\      \n";
	File << "     /   \\     \n";
	File << "    /     \\    \n";
	File << "   /       \\   \n";
	File << "  /         \\  \n";
	File << " /___________\\ \n";
	File << "       |       \n";
	File << "       |       \n";
}