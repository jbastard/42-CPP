#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
	std::string _name;

public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const ClapTrap& copy);
	~DiamondTrap();

	DiamondTrap& operator=(const DiamondTrap& src);
	void whoAmI() const;
	void attack(const std::string& target);
};
