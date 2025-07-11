#include "../includes/DiamondTrap.hpp"

int main(void)
{
	DiamondTrap toto("Toto");
	std::cout << toto;
	toto.whoAmI();
	toto.beRepaired(5);
	std::cout << toto;
	toto.takeDamage(14);
	toto.highFivesGuys();
	std::cout << toto;
}
