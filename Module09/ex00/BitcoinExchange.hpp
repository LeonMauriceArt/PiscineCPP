#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>

#define DATABASE data.csv

class BitcoinExchange
{
	private:
		std::map<std::string, float> input;
		std::map<std::string, float> database;
		void getInput(std::string input);
		void getDatabase(std::string database);
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		BitcoinExchange(std::string inputfile);
		void printExchangeValues();

};


#endif