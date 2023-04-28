#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		std::string const _name;
		unsigned int _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat&other);
		~Bureaucrat();
		std::string getName() const;
		unsigned int getGrade() const;
		void promotion();
		void demotion();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif