#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
	std::string _name;

public:
	DiamondTrap();
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& copy);
	~DiamondTrap();

	DiamondTrap& operator=(const DiamondTrap& src);

	std::string	getName() const;

	void whoAmI() const;
	virtual void	attack(const std::string& target) { ScavTrap::attack(target); }
	virtual void	takeDamage(unsigned int amount) { ScavTrap::takeDamage(amount); }
	virtual void	beRepaired(unsigned int amount) { ScavTrap::beRepaired(amount); }
};

std::ostream& operator<<(std::ostream& out, const DiamondTrap& src);