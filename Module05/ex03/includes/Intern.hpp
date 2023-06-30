#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Intern
{
	private:
		Form *CreateShrubbery(std::string target);
		Form *CreatePresidential(std::string target);
		Form *CreateRobotomy(std::string target);
	public:
		Intern();
		~Intern();
		Form *makeForm(std::string form, std::string target);
};

#endif