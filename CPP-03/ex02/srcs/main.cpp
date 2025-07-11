#include "../includes/FragTrap.hpp"

int main(void)
{
	FragTrap toto("Toto");
	std::cout << toto;
	toto.attack("a training BOT");
	toto.beRepaired(5);
	std::cout << toto;
	toto.takeDamage(14);
	toto.highFivesGuys();
	std::cout << toto;
}
