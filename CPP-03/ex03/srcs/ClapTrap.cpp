#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout
			<< BRIGHT_GREEN "ClapTrap default constructor called" RESET
			<< std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout
			<< BRIGHT_GREEN  "ClapTrap " << "name constructor called" RESET
			<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
	std::cout
			<< BRIGHT_MAGENTA "Copy constructor called" RESET
			<< std::endl;
	*this = src;
}

ClapTrap::~ClapTrap() {
	std::cout
			<< BRIGHT_RED "ClapTrap " << "Destructor called" RESET
			<< std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
	std::cout
			<< BRIGHT_CYAN "Assignment operator called" RESET
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

int getNumLen(int num)
{
	int i = 1;
	for (; num > 9; i++)
		num /= 10;
	return i;
}

std::string	ClapTrap::getName() const {
	return this->_name;
}

int 		ClapTrap::getHitPoints() const {
	return this->_hit_points;
}

int			ClapTrap::getEnergyPoints() const {
	return this->_energy_points;
}

int			ClapTrap::getAttackDamages() const {
	return this->_attack_damage;
}

void ClapTrap::attack(const std::string& target) {
	if (this->_energy_points <= 0 || this->_hit_points <= 0)
	{
		if (this->_hit_points <= 0)
			std::cout
					<< "ClapTrap " << this->_name << " is dead !"
					<< std::endl;
		else if (this->_energy_points <= 0)
			std::cout
					<< "ClapTrap " << this->_name << " don't have enough energy points !"
					<< std::endl;
		return;
	}
	std::cout
		<< BRIGHT_YELLOW "ClapTrap " << this->_name << " attacks " << target << ", causing "<< this->_attack_damage << " points of damage !" RESET
		<< std::endl;
	_energy_points -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hit_points <= 0)
	{
		std::cout
				<< "ClapTrap " << this->_name << " already is dead !"
				<< std::endl;
		return;
	}
	this->_hit_points -= amount;
	std::cout
		<< BRIGHT_RED << "ClapTrap " << this->_name << " took " << amount << " damages" RESET
		<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energy_points <= 0 || this->_hit_points <= 0)
	{
		if (this->_hit_points <= 0)
			std::cout
					<< "ClapTrap " << this->_name << " is dead !"
					<< std::endl;
		else if (this->_energy_points <= 0)
			std::cout
					<< "ClapTrap " << this->_name << " don't have enough energy points !"
					<< std::endl;
		return;
	}
	std::cout
		<< BRIGHT_GREEN << "ClapTrap " << this->_name << " recover " << amount << " health." RESET
		<< std::endl;
	this->_energy_points -= 1;
	this->_hit_points += amount;
}
