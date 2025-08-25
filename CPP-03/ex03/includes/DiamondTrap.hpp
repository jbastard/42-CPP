#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
	std::string _name;

public:
    DiamondTrap();
    explicit DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& copy);
    ~DiamondTrap();

    DiamondTrap&    operator=(const DiamondTrap& other);

	std::string     getName() const;

	void            whoAmI() const;
	void	        attack(const std::string& target);
	void	        takeDamage(unsigned int amount);
	void	        beRepaired(unsigned int amount);
};

std::ostream& operator<<(std::ostream& out, const DiamondTrap& src);
