#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include <iostream>
#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
	private:
		std::string _target;
		static const unsigned int _baseGradeExec = 137;
		static const unsigned int _baseGradeSign = 145;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name, std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &ref);
		~ShrubberyCreationForm();
		std::string get_target(void) const;
		void execute(Bureaucrat const &executor) const;
		void beSigned(const Bureaucrat &b);
};

#endif