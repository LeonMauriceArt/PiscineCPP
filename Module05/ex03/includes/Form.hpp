#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const unsigned int _gradeToSign;
		const unsigned int _gradeToExec;
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		Form();
		Form(std::string name, unsigned int gradeExec, unsigned int gradeSign);
		virtual ~Form();
		Form(const Form &other);
		Form& operator=(const Form &other);
		void beSigned(const Bureaucrat &b);
		unsigned int getGradeToSign() const;
		unsigned int getGradeToExec() const;
		std::string getName() const;
		virtual void execute(Bureaucrat const &executor) const = 0;
		bool isSigned() const;
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif