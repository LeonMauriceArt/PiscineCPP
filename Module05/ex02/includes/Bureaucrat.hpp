#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Form;

class Bureaucrat
{
	private:
		std::string const _name;
		unsigned int _grade;
	public:
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		Bureaucrat();
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat();
		std::string getName() const;
		unsigned int getGrade() const;
		void setGrade(unsigned int grade);
		void promotion();
		void demotion();
		void signForm(Form &f);
		void executeForm(Form const &form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif