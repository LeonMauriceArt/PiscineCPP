#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <cstdlib>
#include <exception>
#include <iostream>

template <class T>
class Array
{
	private:
		T tab[];
	public:
		class OutOfArray: public std::exception
		{
			public :
				virtual const char* what() const throw(); 
		};
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();
		size_t size() const;
		T operator[](size_t index);
};


#endif