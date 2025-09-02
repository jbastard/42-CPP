#pragma once

#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>

class BitcoinExchange{
	private:
		BitcoinExchange();
		std::map<std::string, float> _DB;
		void loadDatabase(const std::string& filename);
	public:
		BitcoinExchange(const std::string& dbFile);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& other);
		BitcoinExchange(const BitcoinExchange& copy);
		float getRateForDate(const std::string& date) const;
		bool isValidDate(const std::string& date) const;
};
