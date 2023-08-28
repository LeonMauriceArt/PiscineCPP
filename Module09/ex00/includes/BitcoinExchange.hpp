#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <string>

#define DATABASE "data.csv"

class BitcoinExchange
{
	private:
		std::map<unsigned int, float> database;
		void getDatabase(std::string database);
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		BitcoinExchange(std::string database);
		bool checkInputLine(std::string inputline);
		void printExchangeValues(std::string filename);
};

unsigned int convertDate(std::string date);

#endif