#ifndef DATE_HPP
#define DATE_HPP

#include "Headers.hpp"
#include "Exceptions.hpp"

#define MAX_YEAR 9999
#define MIN_YEAR 2009
#define MAX_MONTH 12
#define MIN_MONTH 1
#define MAX_DAY 31
#define MIN_DAY 1

class Date
{
	private:
		Date();
		Date &operator=(const Date &other);
		Date(const Date &other);
	public:
		~Date();
		static bool isValidDate(unsigned int year, unsigned int month, unsigned int day);
		static unsigned int convertDate(std::string date);
};

#endif