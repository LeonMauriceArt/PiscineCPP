#include "./includes/BitcoinExchange.hpp"
#include "./includes/Exceptions.hpp"
#include "./includes/Date.hpp"
#include <exception>
#include <fstream>
#include <iostream>

std::map<class Date, float> getInput(std::string filename)
{
	std::ifstream file;
	file.open(filename.c_str());
	std::map<class Date, float> newInput;
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
				Date newdate(date);
				line = line.substr(line.find(",") + 1);
				value = static_cast<float>(std::atof(line.c_str()));
				newInput.insert(std::pair<class Date, float>(newdate, value));
			}
		}
	}
	else {
		throw cannotOpenFile();
	}
	return newInput;
}

int main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return(1);
	}
	BitcoinExchange exchange(DATABASE);
	std::string filename(av[1]);
	std::map<class Date, float> newInput;
	try 
	{
		newInput = getInput(filename);
	} 
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}