
#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "I'm a debug message" << std::endl;
    this->complain("INFO");
}

void Harl::info(void)
{
    std::cout << "I'm a info message" << std::endl;
    this->complain("WARNING");
}

void Harl::warning(void)
{
    std::cout << "I'm a warning message" << std::endl;
    this->complain("ERROR");
}

void Harl::error(void)
{
    std::cout << "I'm a error message" << std::endl;
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
