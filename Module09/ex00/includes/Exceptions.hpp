#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <iostream>

class cannotOpenFile: public std::exception
{
        public:
                virtual const char* what() const throw();
};

class notPositiveNumber: public std::exception
{
        public:
                virtual const char* what() const throw();
};

class badInput: public std::exception
{
        private:
                std::string errorMessage;
        public:
                virtual ~badInput() throw();
                badInput(std::string line);
                virtual const char* what() const throw();
};

#endif