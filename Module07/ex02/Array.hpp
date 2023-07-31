#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <cstdlib>
#include <exception>
#include <iostream>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

template <typename T>
class Array
{
	private:
		T *_tab;
		unsigned int _size;
	public:
		class OutOfArray: public std::exception
		{
			public :
				virtual const char* what() const throw(){
					return ("Error : Out of array !");
				}
		};
		Array(): _size(0){
			this->_tab = new T();
		}
		Array(unsigned int n): _size(n)
		{
			this->_tab = new T[n];
		}			
		Array(const Array &other): _size(other.size())
		{
			if (other._tab)
			{
				this->_tab = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					this->_tab[i] = other._tab[i];
			}
			else 
				this->_tab = new T[0];
		}
		Array &operator=(const Array &other)
		{
			if (this->_tab)
				delete(this->_tab);
			if (other._tab)
			{
				this->_size = other.size();
				this->_tab = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					this->_tab[i] = other._tab[i];
			}
			else
			{
				this->_size = 0;
				this->_tab = new T[0];
			}
			return(*this);
		}
		~Array()
		{
			if (this->_tab)
			delete(this->_tab);
		}
		unsigned int size() const
		{
			return(this->_size);
		}
		T &operator[](unsigned int index)
		{
			try 
			{
				if (index < 0 || index > _size)
					throw OutOfArray();
				return (_tab[index]);
			} 
			catch (std::exception &e) 
			{
				std::cout << RED << e.what() << RESET << std::endl;
				return _tab[0];
			}
		}
		void displayArray()
		{
			for(unsigned int i = 0; i < _size; i++)
				std::cout << _tab[i] << std::endl;
		}
};


#endif