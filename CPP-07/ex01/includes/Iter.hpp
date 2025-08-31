#pragma once

#include <string>
#include <iomanip>
#include <iostream>

template<typename T>
void print(const T& str)
{
	std::cout << str << " ";
}

template <typename T, typename F>
void iter(T* array, size_t length, F function)
{
	if (!array || !function)
		return ;
	for (size_t i = 0; i < length; i++)
		function(array[i]);
}
