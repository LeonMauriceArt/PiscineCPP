#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include "Headers.hpp"

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

class tooHighNumber: public std::exception
{
        public:
                virtual const char* what() const throw();
};

class invalidDate: public std::exception
{
        public:
                virtual const char* what() const throw();
};

class noPreviousValue: public std::exception
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