#include "Harl.hpp"

void    Harl::debug(void)
{
    std::cout << "I'm an debug message" << std::endl;
	this->info();
}

void Harl::info(void)
{
    std::cout << "I'm an info message" << std::endl;
	this->warning();
}

void Harl::warning(void)
{
    std::cout << "I'm an warning message" << std::endl;
	this->error();
}

void Harl::error(void)
{
    std::cout << "I'm an error message" << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*ptr_func[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*ptr_func[i])();
            return;
        }
    }
}

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}