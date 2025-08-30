#pragma once

#include <iomanip>
#include <iostream>
#include <string>
#include <stdint.h>

struct Data {
	std::string name;
	int			value;
};

class Serializer{
	private:
		Serializer();
		~Serializer();
		Serializer& operator=(const Serializer& other);
		Serializer(const Serializer& copy);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
