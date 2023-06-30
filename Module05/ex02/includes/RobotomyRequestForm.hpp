#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"
#include <fstream>

class RobotomyRequestForm : public Form
{
	private:
		std::string _target;
		static const unsigned int _baseGradeExec = 45;
		static const unsigned int _baseGradeSign = 72;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &ref);
		~RobotomyRequestForm();
		std::string get_target(void) const;
		void execute(Bureaucrat const &executor) const;
		void beSigned(const Bureaucrat &b);
};

#endif