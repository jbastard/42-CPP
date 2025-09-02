#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	// std::cout << "BitcoinExchange default constructor has been called" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
	// std::cout << "BitcoinExchange destructor has been called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const std::string& dbFile)
{
	loadDatabase(dbFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	this->_DB = copy._DB;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->_DB = other._DB;
	}
	return *this;
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file)
	{
		std::cerr << "Error: Couldn't open database file." << std::endl;
		std::exit(1);
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::string date, rateStr;
		if (std::getline(ss, date, ',') && std::getline(ss, rateStr))
		{
			float rate = std::strtof(rateStr.c_str(), NULL);
			_DB[date] = rate;
		}
	}
}

float BitcoinExchange::getRateForDate(const std::string& date) const
{
	std::map<std::string, float>::const_iterator it = _DB.lower_bound(date);
	if (it != _DB.end() && it->first == date)
		return it->second;
	if (it == _DB.begin())
		return -1;
	--it;
	return it->second;
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	// get today's date
	std::time_t now = std::time(NULL);
	std::tm* local = std::localtime(&now);
	int currentYear = local->tm_year + 1900;
	int currentMonth = local->tm_mon + 1;
	int currentDay = local->tm_mday;

	// validate date and verifying if date composed of digits
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	for (size_t i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}
	
	// retrieving bitcoin.txt dates
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12 || day < 1)
		return false;

	// checking for leap year
	// reminder : a leap year is a multiplier of 4 but not a multiplier of 100
	// if it is a multiplier of 400, it is also a leap year
	int daysInMonth[] = {31, 28, 31, 30, 31, 30,
						31, 31, 30, 31, 30, 31};

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[1] = 29;

	if (day > daysInMonth[month - 1])
		return false;

	if (year > currentYear)
		return false;
	else if (year == currentYear && month > currentMonth)
		return false;
	else if (year == currentYear && month == currentMonth && day > currentDay)
		return false;

	return true;
}
