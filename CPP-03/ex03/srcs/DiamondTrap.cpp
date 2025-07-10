#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout
			<< BRIGHT_GREEN "Default constructor called" RESET
			<< std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name) {
	std::cout
			<< BRIGHT_GREEN  "DiamondTrap " << "Name constructor called" RESET
			<< std::endl;
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) {
	std::cout
			<< BRIGHT_MAGENTA "Copy constructor called" RESET
			<< std::endl;
	*this = src;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src) {
	std::cout
			<< BRIGHT_CYAN "Copy assignment operator called" RESET
			<< std::endl;

	if (this != &src)
	{
		this->_name = src.getName();
		this->_hit_points = src.getHitPoints();
		this->_energy_points = src.getEnergyPoints();
		this->_attack_damage = src.getAttackDamages();
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout
			<< BRIGHT_RED  "DiamondTrap " << "Destructor called" RESET
			<< std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	if (this->_energy_points <= 0 || this->_hit_points <= 0)
	{
		if (this->_hit_points <= 0)
			std::cout
					<< "DiamondTrap " << this->_name << " is dead !"
					<< std::endl;
		else if (this->_energy_points <= 0)
				std::cout
						<< "DiamondTrap " << this->_name << " don't have enough energy points !"
						<< std::endl;
		return;
	}
	std::cout
			<< BRIGHT_YELLOW "DiamondTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage !" RESET
			<< std::endl;
	_energy_points -= 1;
}

std::ostream& operator<<(std::ostream& out, const DiamondTrap& src) {
	out
			<< BRIGHT_BLUE << "+-------------------------------+" << RESET << std::endl
			<< BRIGHT_BLUE << "|         DiamondTrap Stats        |" << RESET << std::endl
			<< BRIGHT_BLUE << "+-------------------------------+" << RESET << std::endl
			<< BRIGHT_BLUE "|" RESET << "  Name           : " << BRIGHT_WHITE << src.getName() << std::setw(24  - src.getName().length()) << BRIGHT_BLUE "|" RESET << std::endl
			<< BRIGHT_BLUE "|" RESET << "  Health         : " << BRIGHT_WHITE << src.getHitPoints() << std::setw(24  - getNumLen(src.getHitPoints())) << BRIGHT_BLUE "|" RESET << std::endl
			<< BRIGHT_BLUE "|" RESET << "  Attack Damage  : " << BRIGHT_WHITE << src.getAttackDamages() << std::setw(24  - getNumLen(src.getAttackDamages())) << BRIGHT_BLUE "|" RESET << std::endl
			<< BRIGHT_BLUE "|" RESET << "  Energy Points  : " << BRIGHT_WHITE << src.getEnergyPoints() << std::setw(24  - getNumLen(src.getEnergyPoints())) << BRIGHT_BLUE "|" RESET << std::endl
			<< BRIGHT_BLUE << "+-------------------------------+" << RESET << std::endl;
	return out;
}
