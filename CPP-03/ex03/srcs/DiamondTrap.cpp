#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout
			<< BRIGHT_GREEN "Default constructor called" RESET
			<< std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name), FragTrap(name), ScavTrap(name), _name(name) {
	std::cout
			<< BRIGHT_GREEN  "DiamondTrap " << "Name constructor called" RESET
			<< std::endl;
	this->ClapTrap::_name = ClapTrap::_name + "_clap_name";
	this->_name = name;
	this->_hit_points = FragTrap::baseHitPoints;
	this->_energy_points = ScavTrap::baseEnergyPoints;
	this->_attack_damage = FragTrap::baseAttackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), FragTrap(src), ScavTrap(_name) {
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

std::string	DiamondTrap::getName() const {
	return this->_name;
}

void DiamondTrap::whoAmI() const {
	std::cout << "Hello i'm " << this->_name << " and my Clap name is " << this->ClapTrap::_name << " !" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const DiamondTrap& src) {
	out
			<< BRIGHT_BLUE << "+-------------------------------+" << RESET << std::endl
			<< BRIGHT_BLUE << "|       DiamondTrap Stats       |" << RESET << std::endl
			<< BRIGHT_BLUE << "+-------------------------------+" << RESET << std::endl
			<< BRIGHT_BLUE "|" RESET << "  Name           : " << BRIGHT_WHITE << src.getName() << std::setw(24  - src.getName().length()) << BRIGHT_BLUE "|" RESET << std::endl
			<< BRIGHT_BLUE "|" RESET << "  Health         : " << BRIGHT_WHITE << src.getHitPoints() << std::setw(24  - getNumLen(src.getHitPoints())) << BRIGHT_BLUE "|" RESET << std::endl
			<< BRIGHT_BLUE "|" RESET << "  Attack Damage  : " << BRIGHT_WHITE << src.getAttackDamages() << std::setw(24  - getNumLen(src.getAttackDamages())) << BRIGHT_BLUE "|" RESET << std::endl
			<< BRIGHT_BLUE "|" RESET << "  Energy Points  : " << BRIGHT_WHITE << src.getEnergyPoints() << std::setw(24  - getNumLen(src.getEnergyPoints())) << BRIGHT_BLUE "|" RESET << std::endl
			<< BRIGHT_BLUE << "+-------------------------------+" << RESET << std::endl;
	return out;
}
