#include "../includes/BitcoinExchange.hpp"

bool isValueValid(float value)
{
	return value >= 0 && value <= 1000;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange exchange("data.csv");

	std::ifstream input(argv[1]);
	if (!input.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	std::string line;
	std::getline(input, line); // skip header

	while (std::getline(input, line))
	{
		std::istringstream ss(line);
		std::string date, valueStr;

		if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		if (!date.empty() && date[date.size() - 1] == ' ')
			date.erase(date.size() - 1);
		valueStr.erase(0, valueStr.find_first_not_of(" \t"));

		char* endPtr = NULL;
		float value = std::strtof(valueStr.c_str(), &endPtr);

		// conversion check (total or partial)
		if (*endPtr != '\0')
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		// check value < 0
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}

		// check too large value
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		if (!exchange.isValidDate(date))
		{
			std::cerr << "Error: invalid date" << std::endl;
			continue;
		}
		
		else
		{
			float rate = exchange.getRateForDate(date);
			if (rate == -1)
				std::cerr << "Error: no rate found before " << date << std::endl;
			else
			{
				std::cout << date << " => " << value << " = ";
				std::cout << std::fixed << std::setprecision(2) << value * rate << std::endl;
			}
		}
	}

	return 0;
}
