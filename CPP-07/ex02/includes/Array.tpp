#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include "Array.hpp"

template<typename T>
Array<T>::Array()
{
	_array = NULL;
	_size = 0;
	// std::cout << "Array default constructor has been called" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	_array = new T[n]();
	_size = n;
	// std::cout << "Array parametized constructor has been called" << std::endl;
}

template<typename T>
Array<T>::Array(const Array& copy)
{
	_array = NULL;
	_size = 0;
	*this = copy;
	// std::cout << "Array copy constructor has been called" << std::endl;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	// std::cout << "Overload operator '=' has been called" << std::endl;
	if (this != &other)
	{
		delete[] _array;
		_size = other._size;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	return *this;
}

template<typename T>
Array<T>::~Array()
{
	// std::cout << "Array destructor has been called" << std::endl;
	delete[] _array;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	// std::cout << "Operator '[]' overload has been called" << std::endl;
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return _array[index];
}

template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}
