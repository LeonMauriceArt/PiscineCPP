#include "../includes/BitcoinExchange.hpp"
#include "../includes/Exceptions.hpp"
#include "../includes/Date.hpp"
#include <cctype>
#include <sstream>
#include <stdexcept>
#include <string>

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
				try 
				{
					datevalue = Date::convertDate(date);
					line = line.substr(line.find(",") + 1);
					value = static_cast<float>(std::atof(line.c_str()));
					this->database.insert(std::pair<unsigned int, float>(datevalue, value));
				} 
				catch (std::exception &e) 
				{
					std::cout << e.what() << std::endl;
				}
			}
		}
	}
	else {
		throw cannotOpenFile();
	}
}

void	BitcoinExchange::checkInputLine(std::string line)
{
	std::string date;
	std::string::size_type pos = line.find('|');
	std::string remain;
	if (pos != std::string::npos)
	{
		--pos;
		date = line.substr(0, pos);
		if (date.size() != 10)
		{
			throw badInput(line);
		}
		for (size_t i = 0; i < date.size(); ++i)
		{
			if (i == 4 || i == 7)
			{
				if (date[i] != '-')
					throw badInput(line);
			}
			else 
			{
				if (!std::isdigit(date[i]))
					throw badInput(line);
			}
		}
		std::string remaining;
		remaining = line.substr(line.find("|") + 1);
		if (!remaining.empty() && remaining[0] == ' ')
		{
			remaining = remaining.substr(1);
			float f;
			std::istringstream iss(remaining);
			iss >> std::noskipws >> f;
			if (iss.fail() || !iss.eof())
				throw badInput(line);
		}
		else {
			throw badInput(line);
		}
	}
	else {
		throw badInput(line);
	}
}

static std::string intDateToString(unsigned int date)
{
	std::stringstream ss;
	ss << date;
	std::string returnDate = ss.str();
	returnDate.insert(4, "-");
	returnDate.insert(7, "-");
	return returnDate;
}

void	BitcoinExchange::searchInData(unsigned int datevalue, float amount, std::string date)
{
	if (amount < 0)
		throw notPositiveNumber();
	if (amount > 1000)
		throw tooHighNumber();
	std::map<unsigned int, float>::iterator iter = database.find(datevalue);
	if (iter != database.end())
		std::cout << date << " => " << amount << " = " << database.find(datevalue)->second * amount << std::endl;
	else 
	{
		iter = database.lower_bound(datevalue);
		if (iter != database.begin())
		{
			--iter;
			std::cout << intDateToString(iter->first) << " => " << amount << " = " << iter->second * amount << std::endl;
		}
		else 
			throw noPreviousValue();
	}
}

void	BitcoinExchange::printExchangeValues(std::string filename)
{
	std::ifstream file;
	file.open(filename.c_str());
	std::string line;
	std::string date;
	std::string amount;
	unsigned int datevalue;
	float amountvalue;
	if (file.is_open())
	{
		while(file)
		{
			//catching error for each line
			try 
			{
				std::getline(file, line);
				if (line != "" && std::isdigit(line[0]))
				{
					checkInputLine(line);
					std::string::size_type pos = line.find('|');
					--pos;
					date = line.substr(0, pos);
					datevalue = Date::convertDate(date);
					amount = line.substr(line.find("|") + 1);
					amountvalue = static_cast<float>(std::atof(amount.c_str()));
					searchInData(datevalue, amountvalue, date);
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

