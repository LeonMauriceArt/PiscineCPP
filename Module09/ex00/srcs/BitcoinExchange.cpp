#include "../includes/BitcoinExchange.hpp"
#include <cctype>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <sstream>
#include <string>
#include "../includes/Exceptions.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	database = other.database;
}


BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	database = other.database;
	return (*this);
}

BitcoinExchange::BitcoinExchange(std::string database)
{
	getDatabase(database);
}

unsigned int convertDate(std::string date)
{
	std::string processedDate;
	for (size_t i = 0; i < date.size(); ++i)
	{
		if (date[i] != '-')
			processedDate += date[i];
	}
	std::istringstream iss(processedDate);
	unsigned int datevalue = 0;
	iss >> datevalue;
	return datevalue;
}

void BitcoinExchange::getDatabase(std::string database)
{
	std::ifstream file;
	file.open(database.c_str());
	std::string line;
	std::string date;
	float	value;
	unsigned int datevalue;
	if (file.is_open())
	{
		while(file)
		{
			std::getline(file, line);
			std::string::size_type pos = line.find(',');
			if (pos != std::string::npos && std::isdigit(line.c_str()[0]))
			{
				date = line.substr(0, pos);
				datevalue = convertDate(date);
				line = line.substr(line.find(",") + 1);
				value = static_cast<float>(std::atof(line.c_str()));
				this->database.insert(std::pair<unsigned int, float>(datevalue, value));
			}
		}
	}
	else {
		throw cannotOpenFile();
	}
}

void	BitcoinExchange::printExchangeValues(std::string filename)
{
	std::ifstream file;
	try 
	{
		file.open(filename.c_str());
		std::map<unsigned int, float> newInput;
		std::string line;
		std::string date;
		unsigned int datevalue;
		float	value;
		if (file.is_open())
		{
			while(file)
			{
				//catching error for each line
				try 
				{
					std::getline(file, line);
					std::string::size_type pos = line.find('|');
					--pos;
					if (pos != std::string::npos && std::isdigit(line.c_str()[0]))
					{
						date = line.substr(0, pos);
						if (date.size() != 10)
							throw badInput(line);
						std::cout << "date = " << date << "$" << std::endl;
						datevalue = convertDate(date);
						std::cout << "date value = " << datevalue << std::endl;
						line = line.substr(line.find(",") + 1);
						value = static_cast<float>(std::atof(line.c_str()));
					}
				} 
				catch (std::exception &e) 
				{
					std::cout << e.what() << std::endl;
				}
			}
		}
		else 
		{
			throw cannotOpenFile();
		}
	} 
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;
	}
}

