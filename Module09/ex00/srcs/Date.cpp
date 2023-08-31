#include "../includes/Date.hpp"
#include <cctype>
#include <complex>
#include <string>

Date::Date()
{}

Date::Date(const Date &other)
{
	(void)other;
}

Date &Date::operator=(const Date &other)
{
	(void)other;
	return (*this);
}

Date::~Date()
{}

bool Date::isValidDate(unsigned int year, unsigned int month, unsigned int day)
{
	if (year < MIN_YEAR || year > MAX_YEAR)
		return (false);
	if (month < MIN_MONTH || month > MAX_MONTH)
		return (false);
	if (day < MIN_DAY || day > MAX_DAY)
		return (false);
	if (year == 2009 && month == 1 && day < 3)
		return (false);
	return (true);
}

unsigned int Date::convertDate(std::string date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		throw invalidDate();
	std::string remaining;
	std::string toGet;
	unsigned int _year;
	unsigned int _month;
	unsigned int _day;

	//getting the year
	std::string::size_type pos = date.find('-');
	toGet = date.substr(0, pos);
	remaining = date.substr(pos + 1, date.size() - toGet.size());
	for (size_t i = 0; i < toGet.size(); ++i)
	{
		if (!std::isdigit(toGet[i]))
			throw invalidDate();
	}
	_year = static_cast<unsigned int>(std::atof(toGet.c_str()));

	//getting the month
	pos = remaining.find('-');
	toGet = remaining.substr(0, pos);
	remaining = remaining.substr(pos + 1, remaining.size() - toGet.size());
	for (size_t i = 0; i < toGet.size(); ++i)
	{
		if (!std::isdigit(toGet[i]))
			throw invalidDate();
	}
	_month = static_cast<unsigned int>(std::atof(toGet.c_str()));

	//getting the day
	pos = remaining.find('-');
	toGet = remaining.substr(0, pos);
	remaining = remaining.substr(pos + 1, remaining.size() - toGet.size());
	for (size_t i = 0; i < toGet.size(); ++i)
	{
		if (!std::isdigit(toGet[i]))
			throw invalidDate();
	}	
	_day = static_cast<unsigned int>(std::atof(toGet.c_str()));

	//final check before returning unsigned int date
	if (!isValidDate(_year, _month, _day))
		throw invalidDate();
	unsigned int _datevalue = (_year * 100 + _month) * 100 + _day;
	return (_datevalue);
}
