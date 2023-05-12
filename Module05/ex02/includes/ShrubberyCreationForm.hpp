#ifndef SHRUBBERYPARDONFORM_HPP
#define SHRUBBERYPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"
#include <fstream>

class ShrubberyPardonForm : public Form
{
private:
	std::string target;

public:
	ShrubberyPardonForm();
	ShrubberyPardonForm(std::string target);
	ShrubberyPardonForm(ShrubberyPardonForm const &copy);
	ShrubberyPardonForm &operator=(ShrubberyPardonForm const &ref);
	~ShrubberyPardonForm();
	const std::string &get_target(void) const;
	void execute(Bureaucrat const &executor) const;
};

#endif