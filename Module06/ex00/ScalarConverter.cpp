#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <limits>
#include <string>

bool ScalarConverter::isInteger(const std::string &litteral)
{
	for(unsigned long int i = 0; i < litteral.length(); i++)
	{
		if (litteral[0] == '+' || litteral[0] == '-')
			i++;
		if (!std::isdigit(litteral[i]))
			return(false);
	}
	return (true);
}

bool ScalarConverter::isFloat(const std::string &litteral)
{
	if (litteral.compare("nanf") == 0 || litteral.compare("+inff") == 0 || litteral.compare("-inff") == 0)
		return (true);
    char *end;
	std::strtod(litteral.c_str(), &end);
	std::string e(end);
	if(e.length() == 1 && *end == 'f')
		return (true);
	else
		return (false);
}

bool ScalarConverter::isDouble(const std::string &litteral)
{
	if (litteral.compare("nan") == 0 || litteral.compare("+inf") == 0 || litteral.compare("-inf") == 0)
		return (true);
    char *end;
	std::strtod(litteral.c_str(), &end);
	if(*end == '\0')
		return (true);
	else
		return (false);
}

void ScalarConverter::displayResult(char cvalue, int ivalue, float fvalue, double dvalue, std::string &litteral)
{
	if (ivalue >= std::numeric_limits<unsigned char>::min() && ivalue <= std::numeric_limits<char>::max())
	{
		if (!std::isprint(ivalue))
			std::cout << "char: non printable" << std::endl;
		else
			std::cout << "char: '" << cvalue << "'" << std::endl;
	} 
	else
		std::cout << "char: impossible" << std::endl;
	if (ivalue == std::numeric_limits<int>::min() || ivalue == std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << ivalue << std::endl;
	if (fvalue == std::numeric_limits<float>::infinity())
		std::cout << "float: " << std::numeric_limits<float>::infinity() << std::endl;
	else if (fvalue == -std::numeric_limits<float>::infinity())
		std::cout << "float: " << -std::numeric_limits<float>::infinity() << std::endl;
	else if (fvalue == std::numeric_limits<float>::quiet_NaN())
		std::cout << "float: " << std::numeric_limits<float>::quiet_NaN() << std::endl;
	else
		std::cout << "float: " << std::fixed << fvalue << "f" << std::endl;
	if (dvalue == std::numeric_limits<double>::infinity())
		std::cout << "double: " << std::numeric_limits<double>::infinity() << std::endl;
	else if (dvalue == -std::numeric_limits<double>::infinity())
		std::cout << "double: " << -std::numeric_limits<double>::infinity() << std::endl;
	else if (dvalue == std::numeric_limits<double>::quiet_NaN())
		std::cout << "double: " << std::numeric_limits<double>::quiet_NaN() << std::endl;
	else
		std::cout << "double: " << std::fixed << dvalue << std::endl;
}

void ScalarConverter::convertChar(std::string &litteral)
{
	char cvalue;
	if (litteral.length() > 1)
		cvalue = litteral[1];
	else
		cvalue = litteral[0];
	int ivalue = static_cast<int>(cvalue);
	float fvalue = static_cast<float>(cvalue);
	double dvalue = static_cast<double>(cvalue);
	displayResult(cvalue, ivalue, fvalue, dvalue, litteral);
}

void ScalarConverter::convertInt(std::string &litteral)
{
	int ivalue = std::atoi(litteral.c_str());
	char cvalue = static_cast<char>(ivalue);
	float fvalue = static_cast<float>(ivalue);
	double dvalue = static_cast<double>(ivalue);
	long long check = atof(litteral.c_str());
	if (check < std::numeric_limits<int>::min())
		ivalue = std::numeric_limits<int>::min();
	if (check > std::numeric_limits<int>::max())
		ivalue = std::numeric_limits<int>::max();
	displayResult(cvalue, ivalue, fvalue, dvalue, litteral);
}

void ScalarConverter::convertFloat(std::string &litteral)
{
	float fvalue = std::atof(litteral.c_str());
	char cvalue = static_cast<char>(fvalue);
	int ivalue = static_cast<int>(fvalue);
	double dvalue = static_cast<double>(fvalue);
	displayResult(cvalue, ivalue, fvalue, dvalue, litteral);
}

void ScalarConverter::convertDouble(std::string &litteral)
{
	double dvalue = atof(litteral.c_str());
	float fvalue = static_cast<float>(dvalue);
	char cvalue = static_cast<char>(dvalue);
	int ivalue = static_cast<int>(dvalue);
	displayResult(cvalue, ivalue, fvalue, dvalue, litteral);
}

void ScalarConverter::convert(std::string litteral)
{
	if ((litteral.length() == 3 && litteral[0] == '\'' && litteral[2] == '\'') || (litteral.length() == 1 && !std::isdigit(litteral[0])))
    {
        std::cout << "litteral is a character" << std::endl;
		convertChar(litteral);
		return;
    }
	else if(isInteger(litteral))
	{
		std::cout << "litteral is an integer" << std::endl;
		convertInt(litteral);
		return;
	}
	else if(isFloat(litteral))
	{
		std::cout << "litteral is a float" << std::endl;
		convertFloat(litteral);
		return;
	}
	else if (isDouble(litteral))
	{
		std::cout << "litteral is a double" << std::endl;
		convertDouble(litteral);
		return;
	}
	else
		std::cout << "ERROR : Input is not a literal representation" << std::endl;
}