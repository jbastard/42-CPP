#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>

template<typename T>
class Array
{
	private:
	T* _array;
	size_t _size;
	public:
	Array();
	Array(unsigned int n);
	~Array();
	Array& operator=(const Array& other);
	Array(const Array& copy);
	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;
	unsigned int size() const;
};

#include "Array.tpp"
