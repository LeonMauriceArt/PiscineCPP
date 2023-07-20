#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>


template <typename T> void iter(T *tab, std::size_t N, void (*function)(const T &))
{
	if (tab == NULL || function == NULL)
		return;
	for(size_t i = 0; i < N; i++)
		function(tab[i]);
}

template <typename T> void print(const T value)
{
	std::cout << value << std::endl;
}

#endif