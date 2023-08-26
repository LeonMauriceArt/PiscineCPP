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
		std::map<class Date, float> database;
		void getDatabase(std::string database);
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		BitcoinExchange(std::string database);
		bool checkInputLine(std::string inputline);
		void printExchangeValues(std::map<class Date, float> input);
};


#endif