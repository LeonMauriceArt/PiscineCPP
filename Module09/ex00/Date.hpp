#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>

class Date
{
	private:
		unsigned int _year;
		unsigned int _day;
		unsigned int _month;
		Date();
		Date(const Date &other);
		Date &operator=(const Date &other);
	public:
		Date(std::string date);
		~Date();
		unsigned int getYear() const;
		unsigned int getDay() const;
		unsigned int getMonth() const;
};

#endif