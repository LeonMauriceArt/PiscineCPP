#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <string>
#include "Date.hpp"

#define DATABASE "data.csv"

class BitcoinExchange
{
	private:
		std::map<std::string, float> database;
		void getDatabase(std::string database);
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		BitcoinExchange(std::string database);
		void printExchangeValues();
};


#endif