#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	input = other.input;
	database = other.database;
}


BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	input = other.input;
	database = other.database;
	return (*this);
}

BitcoinExchange::BitcoinExchange(std::string database)
{
	getDatabase(database);
}


void BitcoinExchange::getDatabase(std::string database)
{

}