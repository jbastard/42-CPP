
#include "../includes/Zombie.hpp"

int main(void)
{
	Zombie *toto = newZombie("Toto");
	toto->announce();
	randomChump("Foo");
	toto->Zombie::~Zombie();
	return (0);
}