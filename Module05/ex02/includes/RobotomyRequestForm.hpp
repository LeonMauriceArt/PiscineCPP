#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"
#include <fstream>

class RobotomyRequestForm : public Form
{
private:
	std::string _target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &copy);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &ref);
	~RobotomyRequestForm();
	const std::string &get_target(void) const;
	void execute(Bureaucrat const &executor) const;
};

#endif