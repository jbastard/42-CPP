
#include "../includes/Zombie.hpp"

int main(void)
{
	Zombie *toto = newZombie("Toto");
	toto->announce();
	toto->Zombie::~Zombie();
	randomChump("Foo");
	return (0);
}