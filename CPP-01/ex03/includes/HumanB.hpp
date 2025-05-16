
#include "Weapon.hpp"

class HumanB {

private:
	std::string	_name;
	Weapon		_weapon;

public:
	HumanB();
	HumanB(const std::string& name);
	~HumanB();

	void	setWeapon(const Weapon& newWeapon);
	void	attack();

};