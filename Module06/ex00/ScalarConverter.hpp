#ifndef SCALARCONVERTER_HPP 
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>

class ScalarConverter
{
    private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		static bool isInteger(const std::string &litteral);
		static bool isFloat(const std::string &litteral);
		static bool isDouble(const std::string &litteral);
		static void convertChar(std::string &litteral);
		static void convertInt(std::string &litteral);
		static void convertFloat(std::string &litteral);
		static void convertDouble(std::string &litteral);
		static void displayResult(char cvalue, int ivalue, float fvalue, double dvalue, std::string &litteral);
	public:
		static void convert(std::string litteral);
};

#endif