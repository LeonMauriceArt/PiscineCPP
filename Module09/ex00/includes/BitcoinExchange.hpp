#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */

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
		void checkInputLine(std::string inputline);
		void printExchangeValues(std::string filename);
		void searchInData(unsigned int datevalue, float amount, std::string date);
};

unsigned int convertDate(std::string date);

#endif