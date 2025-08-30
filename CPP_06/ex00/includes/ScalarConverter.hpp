#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <cstdlib>


class ScalarConverter{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& other);

		static bool isChar(const std::string& str);
		static bool isInt(const std::string& str);
		static bool isDouble(const std::string& str);
		static bool isFloat(const std::string& str);
		static bool isSpecial(const std::string& str);

		static void printChar(char c);
		static void printInt(int i);
		static void printDouble(double d);
		static void printFloat(float f);
		static void printSpecial(const std::string& str);
	public:
		static void convert(const std::string& str);
};
