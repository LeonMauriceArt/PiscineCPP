#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"
#include <fstream>

class PresidentialPardonForm : public Form
{
	private:
		std::string _target;
		static const unsigned int _baseGradeExec = 5;
		static const unsigned int _baseGradeSign = 25;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string name, std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &ref);
		~PresidentialPardonForm();
		std::string get_target(void) const;
		void execute(Bureaucrat const &executor) const;
		void beSigned(const Bureaucrat &b);
};
#endif