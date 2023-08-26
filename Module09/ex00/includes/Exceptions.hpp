#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>

class cannotOpenFile: public std::exception
{
        public:
                virtual const char* what() const throw();
};

#endif