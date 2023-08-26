#include "../includes/Exceptions.hpp"

const char *cannotOpenFile::what() const throw()
{
        return ("Error: could not open file.");
}