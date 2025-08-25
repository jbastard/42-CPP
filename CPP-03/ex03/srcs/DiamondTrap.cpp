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

void DiamondTrap::takeDamage(unsigned int amount) {
    if (this->_hit_points <= 0)
    {
        std::cout
                << "DiamondTrap " << this->_name << " already is dead !"
                << std::endl;
        return;
    }
    this->_hit_points -= amount;
    std::cout
            << BRIGHT_RED << "DiamondTrap " << this->_name << " took " << amount << " damages" RESET
            << std::endl;
}

void DiamondTrap::beRepaired(unsigned int amount) {
    if (this->_energy_points <= 0 || this->_hit_points <= 0)
    {
        if (this->_hit_points <= 0)
            std::cout
                    <<  "DiamondTrap " << this->_name << " is dead !"
                    << std::endl;
        else if (this->_energy_points <= 0)
            std::cout
                    <<  "DiamondTrap " <<  this->_name << " don't have enough energy points !"
                    << std::endl;
        return;
    }
    std::cout
            << BRIGHT_GREEN "DiamondTrap " << this->_name << " recover " << amount << " health." RESET
            << std::endl;
    this->_energy_points -= 1;
    this->_hit_points += amount;
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
