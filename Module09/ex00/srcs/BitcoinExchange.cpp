#include "../includes/BitcoinExchange.hpp"
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <string>
#include <utility>

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


void BitcoinExchange::getDatabase(std::string database)
{
	std::ifstream file;
	file.open(database.c_str());
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

void	BitcoinExchange::printExchangeValues(std::map<class Date, float> input)
{
	
}