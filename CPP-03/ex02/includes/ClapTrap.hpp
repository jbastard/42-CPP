#include <iostream>
#include <iomanip>

#define RESET "\033[0m"

#define BRIGHT_BLACK   "\033[1;90m"
#define BRIGHT_RED     "\033[1;91m"
#define BRIGHT_GREEN   "\033[1;92m"
#define BRIGHT_YELLOW  "\033[1;93m"
#define BRIGHT_BLUE    "\033[1;94m"
#define BRIGHT_MAGENTA "\033[1;95m"
#define BRIGHT_CYAN    "\033[1;96m"
#define BRIGHT_WHITE   "\033[1;97m"

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
