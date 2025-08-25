#pragma once
#include <iostream>
#include <iomanip>
#include "Colors.hpp"

#define RESET "\033[0m"

class ClapTrap {
protected:
	std::string	_name;
	int			_hit_points;
	int			_energy_points;
	int			_attack_damage;

public:
	ClapTrap();
	ClapTrap(const std::string& name);
	explicit ClapTrap(const ClapTrap& copy);
	~ClapTrap();

	ClapTrap&       operator=(const ClapTrap& src);

    virtual         std::string	getName() const;
	int 	        getHitPoints() const;
	int		        getEnergyPoints() const;
	int		        getAttackDamages() const;

    virtual void	attack(const std::string& target);
    virtual void	takeDamage(unsigned int amount);
    virtual void	beRepaired(unsigned int amount);
};

int				getNumLen(int num);
std::ostream&	operator<<(std::ostream& out, const ClapTrap& src);
