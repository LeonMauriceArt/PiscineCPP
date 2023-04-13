#include "Harl.hpp"

int whatLevel(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
		if (levels[i] == level)
			return (i);
	return (-1);
}

int main(int ac, char *av[])
{
	if (ac != 2 && av[0])
	{
		std::cout << "Usage : ./HarlFilter <level>" << std::endl << "Levels can be DEBUG, INFO, WARNING OR ERROR" << std::endl; 
		return (1);
	}
    Harl myHarl;
	std::string str = av[1];
	switch (whatLevel(str))
	{
	case 0:
		myHarl.complain("DEBUG");
		break;
	case 1:
		myHarl.complain("INFO");
		break;
	case 2:
		myHarl.complain("WARNING");
		break;
	case 3:
		myHarl.complain("ERROR");
		break;
	default:
		std::cout << "Unknown level" << std::endl;
		break;
	}
    return (0);
}
