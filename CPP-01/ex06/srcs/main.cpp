
#include "../includes/Harl.hpp"

int	get_level(std::string	level)
{
	int level_index = 0;
	if (level == "DEBUG")
		level_index = 1;
	if (level == "INFO")
		level_index = 2;
	if (level == "WARNING")
		level_index = 3;
	if (level == "ERROR")
		level_index = 4;
	return (level_index);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << ERR_ARGS, 0);

	Harl harl;
	int level = get_level((std::string)av[1]);
	switch (level) {
		default:
			std::cout << UNEXPECTED_ARGS;
			break;
		case 1:
			harl.complain("DEBUG");
		case 2:
			harl.complain("INFO");
		case 3:
			harl.complain("WARNING");
		case 4:
			harl.complain("ERROR");
	}
}
