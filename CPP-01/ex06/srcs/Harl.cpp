
#include "../includes/Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug()	{std::cout << BRIGHT_BLUE << DEBUG_MSG << RESET << std::endl;}
void	Harl::info()	{std::cout << BRIGHT_GREEN << INFO_MSG << RESET << std::endl;}
void	Harl::warning() {std::cout << BRIGHT_ORANGE << WARNING_MSG << RESET << std::endl;}
void	Harl::error()	{std::cout << BOLD_BRIGHT_RED << ERROR_MSG << std::endl;}

void	Harl::complain(std::string level) {

	std::string		level_index[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	HarlFunction	function_tab[] = {
			&Harl::debug,
			&Harl::info,
			&Harl::warning,
			&Harl::error
	};

	for (int i = 0; i < 4; i++)
	{
		if (level == level_index[i])
			(this->*function_tab[i])();
	}
}
