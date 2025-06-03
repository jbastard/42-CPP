
#include "../includes/Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << ERR_ARGS, 0);
	Harl harl;

	harl.complain(av[1]);
}
