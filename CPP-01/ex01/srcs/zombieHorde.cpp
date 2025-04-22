
# include "../includes/Zombie.hpp"

Zombie*	zombieHorde(int N, const std::string& name)
{
	Zombie *zombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombieHorde[i].setName(name);
	return (zombieHorde);
}
