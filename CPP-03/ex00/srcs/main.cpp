#include "../includes/ClapTrap.hpp"

int main(void)
{
	ClapTrap toto("Toto");
	std::cout << toto;
	toto.attack("a training BOT");
	for (int i = 0; i < 10; i++)
		toto.beRepaired(5);
	std::cout << toto;
	toto.takeDamage(14);
	std::cout << toto;
}
