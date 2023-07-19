#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

typedef void (*fun_ptr)();

template <typename T> void iter(T *tab, std::size_t N, void (*function)(T &))
{
	if (tab == NULL || function == NULL)
		return;
	for(size_t i = 0; i < N; i++)
		function(tab[i]);
}

#endif