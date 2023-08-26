#include "Date.hpp"

Date::Date()
{

}

Date::Date(const Date &other)
{
	_year = other.getYear();
	_month = other.getMonth();
	_day = other.getDay();
}

Date &Date::operator=(const Date &other)
{
	_year = other.getYear();
	_month = other.getMonth();
	_day = other.getDay();
	return (*this);
}

Date::Date(std::string date)
{
	std::string year;
	year = date.substr(0, 4);
	std::cout << year << std::endl;
}

Date::~Date()
{
}

unsigned int Date::getYear() const
{
	return _year;
}

unsigned int Date::getDay() const
{
	return _day;
}

unsigned int Date::getMonth() const
{
	return _month;
}