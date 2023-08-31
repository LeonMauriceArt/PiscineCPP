#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "Headers.hpp"
#include "Exceptions.hpp"

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


#endif