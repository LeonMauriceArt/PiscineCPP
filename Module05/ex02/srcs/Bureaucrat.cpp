#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"


Bureaucrat::Bureaucrat(): _name("Unknown"), _grade(150)
{
	std::cout << "Unknown bureaucrat created with grade " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat named " << this->getName() << " created with grade " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other.getName()), _grade(other.getGrade())
{
	std::cout << "Bureaucrat named " << this->getName() << " created with grade " << this->getGrade() << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	this->_grade = other.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat named " << this->getName() << " with grade " << this->getGrade() << " deleted" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::setGrade(unsigned int grade)
{
	this->_grade = grade;
}

void Bureaucrat::promotion()
{
	if (this->getGrade() - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::demotion()
{
	if (this->getGrade() + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Grade too High !");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too Low !");
}

void Bureaucrat::signForm(Form &form)
{
	if (form.isSigned() == true)
	{
		std::cout << this->getName() << " couldn't sign "<< form.getName() << " because it is already signed." << std::endl;
		return;
	}
	else
	{
		try
		{
			form.beSigned(*this);
			std::cout << this->getName() << " signed " << form.getName() << std::endl;
		}
		catch(Form::GradeTooLowException &e)
		{
			std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
			throw(GradeTooLowException());
		}
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (out); 
}

void Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}