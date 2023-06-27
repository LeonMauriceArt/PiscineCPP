#include "./includes/Bureaucrat.hpp"
#include "./includes/Form.hpp"
#include "./includes/ShrubberyCreationForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"

int main()
{
	try
	{
		RobotomyRequestForm robotform("Robotomizing private Brian", "Brian");
		PresidentialPardonForm presidentialform("Galactic pardon", "Vador");
		Bureaucrat Henry("Henry", 155);
		Henry.signForm(robotform);
		Henry.executeForm(robotform);
		Henry.signForm(presidentialform);
		Henry.executeForm(presidentialform);
	}
	catch(const std::exception& e)
	{
		std::cerr << "An error was encountered : " << e.what() << '\n';
	}
	return (0);
}