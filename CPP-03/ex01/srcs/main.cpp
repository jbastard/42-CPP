#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main(void)
{
	ScavTrap toto("Toto");
	toto.attack("a training BOT");
	std::cout << toto;
	toto.beRepaired(5);
	std::cout << toto;
	toto.takeDamage(14);
	toto.guardGate();
	std::cout << toto;
}
