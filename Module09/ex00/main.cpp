#include "BitcoinExchange.hpp"
#include "Date.hpp"
#include <fstream>
#include <iostream>

std::map<class Date, float> getInput(std::ifstream file)
{
	std::string line;
	std::string date;
	float	value;
	if (file.is_open())
	{
		while(file)
		{
			std::getline(file, line);
			std::string::size_type pos = line.find(',');
			if (pos != std::string::npos && std::isdigit(line.c_str()[0]))
			{
				date = line.substr(0, pos);
				line = line.substr(line.find(",") + 1);
				value = static_cast<float>(std::atof(line.c_str()));
				this->database.insert(std::pair<std::string, float>(date, value));
			}
		}
	}
}

int main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		Date date("2019-02-12");
		std::cout << "Error: could not open file." << std::endl;
		return(1);
	}
	BitcoinExchange exchange(DATABASE);
	std::string input(av[1]);
	std::ifstream file;
	file.open(input.c_str());
	if (file.is_open())
	{
		std::map<class Date, float> inputMap = getInput(file);
	}
	else 
	{
		std::cout << "Error: invalid file."
	}
	return (0);
}