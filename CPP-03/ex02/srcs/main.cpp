#include "../includes/FragTrap.hpp"

int main(void)
{
	FragTrap toto("Toto");
	toto.attack("a training BOT");
	std::cout << toto;
	toto.beRepaired(5);
	std::cout << toto;
	toto.takeDamage(14);
	toto.highFivesGuys();
	std::cout << toto;
}
