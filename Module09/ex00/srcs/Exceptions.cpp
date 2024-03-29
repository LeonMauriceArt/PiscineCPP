#include "../includes/Exceptions.hpp"

const char *cannotOpenFile::what() const throw()
{
        return ("Error: could not open file.");
}

const char *notPositiveNumber::what() const throw()
{
        return ("Error: not a positive number.");
}

const char *tooHighNumber::what() const throw()
{
        return ("Error: too high amount (between 0 and 1000).");
}

const char *invalidDate::what() const throw()
{
        return ("Error: invalid date.");
}

const char *noPreviousValue::what() const throw()
{
        return ("Error: no previous value.");
}

badInput::badInput(std::string errorline)
{
        std::string message = "Error: bad input => ";
        message.append(errorline);
        errorMessage = message;
}

badInput::~badInput() throw() 
{
}

const char *badInput::what() const throw()
{
        return (errorMessage.c_str());
}