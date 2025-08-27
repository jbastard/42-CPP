#pragma once

#include "Colors.hpp"
#include <iostream>
#include <iomanip>

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

	ClapTrap& operator=(const ClapTrap& src);

	std::string	getName() const;
	int 		getHitPoints() const;
	int			getEnergyPoints() const;
	int			getAttackDamages() const;

	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
};

int				getNumLen(int num);
std::ostream&	operator<<(std::ostream& out, const ClapTrap& src);
