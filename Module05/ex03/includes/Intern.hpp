#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Intern
{
	private:
		int whatForm(std::string form);
	public:
		Intern();
		~Intern();
		Form *makeForm(std::string form, std::string target);
};

#endif