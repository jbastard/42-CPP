
#include <cstdlib>
#include "../includes/Zombie.hpp"

Zombie*	zombieHorde(int N, const std::string& name);

bool	is_num(std::string str)
{
	if (str.empty())
		return (false);
	for (int i = 0; str[i]; i++)
		if (!isdigit(str[i]))
			return (false);
	return (true);
}

int		main(int ac, char **av)
{
	if (ac != 3)
		return(std::cout << ERR_ARGS << std::endl, 0);
	if (!is_num(av[1]))
		return (std::cout << ERR_ARGS << std::endl, 0);

	int	N				= std::atoi(av[1]);
	std::string name	= av[2];
	Zombie *zombies = zombieHorde(N, name);

	std::cout
		<< GREEN <<"Creating a horde of "
		<< N << " Zombies who are named: "
		<< name << RESET
		<< std::endl;
	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete[] zombies;

	return(0) ;
}
