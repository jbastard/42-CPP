#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main(void)
{
	ScavTrap toto("Toto");
	std::cout << toto;
	toto.attack("a training BOT");
	toto.beRepaired(5);
	std::cout << toto;
	toto.takeDamage(14);
	toto.guardGate();
	std::cout << toto;
}
