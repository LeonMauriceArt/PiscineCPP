#include "Array.hpp"
#include <cstddef>
#include <exception>

template <typename T>
Array<T>::Array()
{
	this->tab = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->tab = new T[n];
}

template <typename T>
Array<T>::Array(const Array &other)
{
	if (other.tab)
	{
		this->tab = new T[other.size()];
		for (size_t i = 0; i < other.size(); i++)
			this->tab[i] = other.tab[i];
	}
	else 
		this->tab = new T[0];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this->tab)
		delete(this->tab);
	if (other.tab)
	{
		this->tab = new T[other.size()];
		for (size_t i = 0; i < other.size(); i++)
			this->tab[i] = other.tab[i];
	}
	else 
		this->tab = new T[0];
}

template <typename T>
Array<T>::~Array()
{
	delete(this->tab);
}

template <typename T>
size_t Array<T>::size() const
{
	size_t size = 0;
	while (this->tab[size])
		size++;
	return (size);
}

template <typename T>
T Array<T>::operator[](size_t index)
{
	try 
	{
		if (index < 0 || index > this->size())
			throw OutOfArray();
		return this->tab[index];
	} 
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;
	}
}

template<typename T>
const char *Array<T>::OutOfArray::what() const throw()
{
	return ("Error : Out of array !");
}