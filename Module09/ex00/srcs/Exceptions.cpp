#include "../includes/Exceptions.hpp"

const char *cannotOpenFile::what() const throw()
{
        return ("Error: could not open file.");
}

const char *notPositiveNumber::what() const throw()
{
        return ("Error: not a positive number.");
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